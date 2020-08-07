#include "User.hpp"
#include <string>
#include <vector>
#include <functional>
#include "Wallet.hpp"
#include "../Exception.hpp"
#include "../hotel/Reservation.hpp"
#include <iostream>
#include "../filter/Filter.hpp"
#include "../filter/FilterPrice.hpp"
#include "Sort.hpp"
#include "Weight.hpp"

#define REFUND_REDUCTION 2
#define MINIMUM_RESERVATIONS_REQUIRED 10
#define DEFAULT_MIN 0
#define DEFAULT_MAX 10
#define ID_SORT "id"
#define MINIMUM_RATINGS_REQUIRED 5
#define ACTIVE_MODE "true"
#define DEACTIVE_MODE "false"

using namespace std;

typedef vector<double> _transactions;

User::User(string _username, string _email, string password)
{
    username = _username;
    email = _email;
    hash<string> string_hash;
    password_hash = string_hash(password);
    wallet = new Wallet;
    reservation_id_counter = 0;
    active_default_filter_price = true;
    sort = new Sort(ID_SORT, ASCENDING);
    active_manual_weight = false;
    personal_weight_should_change = false;
    estimated_weight = new Weight();
}

User::~User()
{
    delete wallet;
}

void User::set_sort(Sort* _sort)
{
    sort = _sort;
    sort->add_ratings(ratings);
}

Weight* User::get_estimated_weights()
{
    if (ratings.size() < MINIMUM_RATINGS_REQUIRED)
        throw InsufficientRatings();
    if (personal_weight_should_change)
        {
            estimated_weight->calculate_weights(ratings_to_vector());
            personal_weight_should_change = false;
        }
    return estimated_weight;
}

void User::set_manual_weights(Weight* weight)
{
    manual_weight = weight;
    active_manual_weight = true;
}

string User::get_manual_weight_mode()
{
    if (active_manual_weight)
        return ACTIVE_MODE;
    return DEACTIVE_MODE;
}

void User::handle_personal_rating()
{
    if (active_manual_weight)
        sort->set_weight(manual_weight);
    else if (sort->needs_estimated_weights() && ratings.size() < MINIMUM_RATINGS_REQUIRED)
        throw InsufficientRatings();
    else if (personal_weight_should_change)
    {
        estimated_weight->calculate_weights(ratings_to_vector());
        sort->set_weight(estimated_weight);
        personal_weight_should_change = false;
    }
    else
        sort->set_weight(estimated_weight);
}

vector<Rating*> User::ratings_to_vector()
{
    vector<Rating*> ratings_vector;
    for (auto it = ratings.begin(); it != ratings.end(); it++)
        ratings_vector.push_back((*it).second);
    return ratings_vector;
}

void User::add_rating(Hotel* hotel, Rating* rating)
{
    ratings[hotel] = rating;
    if (ratings.size() >= MINIMUM_RATINGS_REQUIRED)
        personal_weight_should_change = true;
}

void User::deactivate_manual_weights()
{
    active_manual_weight = false;
}

bool User::can_apply_default_price_filter()
{
    if (reservations.size() < MINIMUM_RESERVATIONS_REQUIRED || !active_default_filter_price)
        return false;
    for (auto it = filters.begin(); it != filters.end(); it++)
        if ((*it)->is_same(new FilterPrice(DEFAULT_MIN, DEFAULT_MAX)))
            return false;
    return true;
}

void User::delete_filters()
{
    for (auto it = filters.begin(); it != filters.end(); it++)
        delete (*it);
    filters.clear();
}

void User::add_filter(Filter* filter)
{
    for (auto it = filters.begin(); it != filters.end(); it++)
        if (filter->is_same(*it))
        {
            filters.erase(it);
            break;
        }  
    filters.push_back(filter);
}

Reservation* User::cancel_reservation(int id)
{
    Reservation* canceled_reservation = remove_reservation(id);
    double refund = canceled_reservation->get_price() / REFUND_REDUCTION;
    wallet->add_credit(refund);
    return canceled_reservation;
}

Reservation* User::remove_reservation(int id)
{
    Reservation* reservation = NULL;
    for (auto it = reservations.begin(); it != reservations.end(); it++)
        if ((*it)->get_id() == id)
            {
                reservation = *it;
                reservations.erase(it);
                break;
            }
    if (reservation == NULL)
        throw NotFound();
    return reservation;
}

void User::add_reservation(Reservation* reservation)
{
    reservation->set_id(get_next_reservation_id());
    wallet->decrease_credit(reservation->get_price());
    reservations.push_back(reservation);
}

void User::check_credit(double amount)
{
    if (!wallet->has_credit(amount))
        throw NotEnoughCredit();
}

int User::get_next_reservation_id()
{
    return ++reservation_id_counter;
}

_transactions User::get_transactions()
{
    return wallet->get_transactions();
}

bool User::is_correct_password(size_t hash)
{
    return hash == password_hash;
}