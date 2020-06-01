#include "User.hpp"
#include <string>
#include <vector>
#include <functional>
#include "Wallet.hpp"
#include "../Exception.hpp"
#include "../hotel/Reservation.hpp"
#include <iostream>
#include "../filter/Filter.hpp"

#define REFUND_REDUCTION 2

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
}

User::~User()
{
    delete wallet;
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