#include "Utrip.hpp"
#include <string>
#include "io//HotelDataParser.hpp"
#include "hotel/HotelDatabase.hpp"
#include "user/UserDatabase.hpp"
#include <functional>
#include "user/User.hpp"
#include "user/Wallet.hpp"
#include "io/Output.hpp"
#include <algorithm>
#include <iostream>
#include "hotel/Hotel.hpp"
#include "hotel/RoomManager.hpp"
#include "hotel/Reservation.hpp"
#include "Exception.hpp"
#include "filter/Filter.hpp"
#include "filter/FilterCity.hpp"
#include "filter/FilterPrice.hpp"
#include "filter/FilterRoom.hpp"
#include "filter/FilterStar.hpp"
#include "filter/FilterDefaultPrice.hpp"
#include "user/Sort.hpp"
#include "user/Weight.hpp"

#define MAX_STAR 5
#define MINIMUM_WEIGHT 1
#define MAXIMUM_WEIGHT 5

using namespace std;

typedef vector<double> _transactions;
typedef std::vector<std::string> _room_ids;
typedef std::vector<Reservation*> _reservations;

Utrip::Utrip()
{
    hotel_database = new HotelDatabase();
    user_database = new UserDatabase();
}

Utrip::~Utrip()
{
    delete hotel_database;
    delete user_database;
}

User* Utrip::get_user_by_username(string username)
{
    return user_database->get_user_by_username(username);
}

Hotel* Utrip::get_hotel_by_id(string id)
{
    return hotel_database->get_hotel_by_id(id);
}

void Utrip::deactivate_manual_weights(User* user)
{
    user->deactivate_manual_weights();
    output->ok_request();
}

void Utrip::activate_manual_weights(User* user, double location_w, double cleanliness_w, double staff_w, double facilities_w, double value_for_money_w)
{
    vector<double> weights = {location_w, cleanliness_w, staff_w, facilities_w, value_for_money_w};
    check_weights(weights);
    Weight* weight = new Weight(location_w, cleanliness_w, staff_w, facilities_w, value_for_money_w);
    user->set_manual_weights(weight);
    output->ok_request();
}

void Utrip::show_estimated_weights(User* user)
{
    Weight* weight = user->get_estimated_weights();
    output->show_estimated_weights(weight);
}

void Utrip::show_manual_weights(User* user)
{
    Weight* weight = user->get_manual_weights();
    output->show_manual_weights(weight, user->get_manual_weight_mode());
}


void Utrip::handle_user_sort(User* user, _hotels& hotels)
{
    user->handle_personal_rating();
    user->get_sort()->sort_hotels(hotels);
}

void Utrip::add_sort_to_user(User* user, string property, bool order)
{               
    Sort* sort = new Sort(property, order);
    user->set_sort(sort);
    output->ok_request();
}

void Utrip::deactivate_default_price_filter(User* user)
{
    user->deactivate_default_price_filter();
    output->ok_request();
}

void Utrip::activate_default_price_filter(User* user)
{
    user->activate_default_price_filter();
    output->ok_request();
}

void Utrip::read_hotel_info_from_csv(string hotel_file_dir, string rating_file_dir)
{
    HotelDataParser parser(hotel_database, hotel_file_dir, rating_file_dir);
    parser.read_data();
}

void Utrip::add_price_filter(User* user, double min_price, double max_price)
{
    check_prices(min_price, max_price);
    FilterPrice* new_filter = new FilterPrice(min_price, max_price);
    user->add_filter(new_filter);
    output->ok_request();
}

void Utrip::add_star_filter(User* user, int min_star, int max_star)
{
    check_stars(min_star, max_star);
    FilterStar* new_filter = new FilterStar(min_star, max_star);
    user->add_filter(new_filter);
    output->ok_request();
}

void Utrip::add_room_filter(User* user, std::string room_type, int quantity, int check_in, int check_out)
{
    FilterRoom* new_filter = new FilterRoom(room_type, quantity, check_in, check_out);
    user->add_filter(new_filter);
    output->ok_request();
}

void Utrip::delete_filters(User* user)
{
    user->delete_filters();
    output->ok_request();
}

void Utrip::add_city_filter(User* user, string city)
{
    FilterCity* new_filter = new FilterCity(city);
    user->add_filter(new_filter);
    output->ok_request();
}

void Utrip::show_average_ratings(string hotel_id)
{
    Hotel* hotel = hotel_database->get_hotel_by_id(hotel_id);
    Rating* average_ratings = hotel->get_average_ratings();
    output->show_average_ratings(average_ratings);
}

void Utrip::show_comments(string hotel_id)
{
    Hotel* hotel = hotel_database->get_hotel_by_id(hotel_id);
    _comments comments = hotel->get_comments();
    output->show_comments(comments);
}

void Utrip::add_rating(User* user, string hotel_id, double location, double cleanliness, double staff, double facilities, double value_for_money, double overall_rating)
{
    Hotel* hotel = hotel_database->get_hotel_by_id(hotel_id);
    Rating* rating =  new Rating(location, cleanliness, staff, facilities, value_for_money, overall_rating);
    hotel->add_rating(user, rating);
    user->add_rating(hotel, rating);
    output->ok_request();
}

void Utrip::add_comment(User* user, string hotel_id, string comment)
{
    Hotel* hotel = hotel_database->get_hotel_by_id(hotel_id);
    Comment new_comment(user, comment);
    hotel->add_comment(new_comment);
    output->ok_request();
}

void Utrip::delete_reservation(User* user, int id)
{
   Reservation* reservation = user->cancel_reservation(id); 
   Hotel* hotel = hotel_database->get_hotel_by_id(reservation->get_hotel_id());
   hotel->get_room_manager()->cancel_reservation(reservation);
   output->ok_request();
}

void Utrip::show_reservations(User* user)
{
    _reservations reservations = user->get_reservations();
    check_empty(reservations.size());
    reverse(reservations.begin(), reservations.end());
    output->show_reservations(reservations);
}

void Utrip::post_reservation(User* user, string hotel_id, string room_type, int quantity, int check_in, int check_out)
{
    RoomManager* hotel_room_manager = hotel_database->get_hotel_by_id(hotel_id)->get_room_manager();
    double total_price = hotel_room_manager->get_reservation_one_night_price(room_type, quantity) * (check_out - check_in + 1);
    user->check_credit(total_price);
    Reservation* reservation = hotel_room_manager->reserve_rooms(room_type, quantity, check_in, check_out);
    reservation->set_hotel_id(hotel_id);
    user->add_reservation(reservation);
    output->show_reserved_rooms_ids(reservation->get_room_ids());
}

void Utrip::handle_default_price_filter(User* user)
{
    if (!user->can_apply_default_price_filter())
        return;
    Filter* new_filter = new FilterDefaultPrice(user->get_reservations());
    user->add_filter(new_filter);
    output->show_default_price_filter_activation();
}

_hotels Utrip::show_hotels(User* user)
{
    handle_default_price_filter(user);
    _filters filters = user->get_filters();
    _hotels hotels = hotel_database->get_hotels();
    for (auto it = filters.begin(); it != filters.end(); it++)
        hotels = (*it)->meet_criteria(hotels);
    handle_user_sort(user, hotels);
    check_empty(hotels.size());
    return hotels;
}

void Utrip::show_hotel(string id)
{
    Hotel* hotel = hotel_database->get_hotel_by_id(id);
    output->show_hotel_info(hotel);
}

void Utrip::show_transactions(User* user, int count)
{
    vector<double> transactions = user->get_transactions();
    reverse(transactions.begin(), transactions.end());
    output->show_transactions(transactions, count);
}

void Utrip::logout(User* user)
{   
    user->delete_filters();
    output->ok_request();
}

void Utrip::add_to_wallet(User* user, double amount)
{
    user->get_wallet()->add_credit(amount);
    output->ok_request();
}

User* Utrip::login(string email, string password)
{
    hash<string> string_hash;
    User* user = user_database->login(email, string_hash(password));
    cerr << user->get_username() << user->get_email() << endl;
    output->ok_request();
    return user;
}

User* Utrip::signup(string username, string email, string password)
{
    cerr << "SIGNUP: " << username << "  " << email << endl;
    User* user = user_database->signup(username, email, password);
    output->ok_request();
    return user;
}

void Utrip::check_weights(vector<double> weights)
{
    for (auto it = weights.begin(); it != weights.end(); it++)
        if (*it < MINIMUM_WEIGHT, *it > MAXIMUM_WEIGHT)
            throw BadRequest();
}

void Utrip::check_prices(double min, double max)
{
    if (min < 0 || max < min)
        throw BadRequest();
}

void Utrip::check_stars(int min, int max)
{
    if (max < min || min < 0 || max > MAX_STAR)
        throw BadRequest();
}

void Utrip::check_empty(int size)
{
    if (size == 0)
        throw EmptyList();
}

