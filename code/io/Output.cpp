#include "Output.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "../hotel/Hotel.hpp"
#include <algorithm>
#include "../hotel/RoomManager.hpp"
#include <iomanip>
#include "../hotel/Reservation.hpp"
#include "../hotel/Rating.hpp"
#include "../user/User.hpp"
#include <map>
#include "output_definitions.hpp"
#include "../user/Weight.hpp"

using namespace std;

typedef vector<double> _transactions;
typedef map<int,int> RoomInfo;

void Output::show_estimated_weights(Weight* weight)
{
    vector<long double> weights = weight->get_weights();
    show_weights(weights);
}

void Output::show_manual_weights(Weight* weight, string mode)
{
    cout << ACTIVE << mode << WEIGHT_DELIMITER;
    if (mode == DEACTIVE)
    {
        cout << endl;
        return;
    } 
    vector<long double> weights = weight->get_weights();
    show_weights(weights);
}

void Output::show_weights(_weights weights)
{
    cout << setprecision(DEFUALT_PRECISION) << fixed;
    cout << WEIGHT_LOCATION << weights[location] << WEIGHT_DELIMITER;
    cout << WEIGHT_CLEANLINESS << weights[cleanliness] << WEIGHT_DELIMITER;
    cout << WEIGHT_STAFF << weights[staff] << WEIGHT_DELIMITER;
    cout << WEIGHT_FACILITIES << weights[facilities] << WEIGHT_DELIMITER;
    cout << WEIGHT_VALUE_FOR_MONEY << weights[value_for_money] << endl;
}

void Output::show_hotels(_hotels hotels)
{
    for (auto it = hotels.begin(); it != hotels.end(); it++)
    {
        cout << (*it)->get_unique_id() << HOTEL_INFO_DELIMITER;
        cout << (*it)->get_properties().name << HOTEL_INFO_DELIMITER;
        cout << (*it)->get_properties().rating << HOTEL_INFO_DELIMITER;
        cout << (*it)->get_location().city << HOTEL_INFO_DELIMITER;
        cout << (*it)->get_room_manager()->get_total_number_of_rooms() << HOTEL_INFO_DELIMITER;
        cout << setprecision(DEFUALT_PRECISION) << fixed;
        cout << (*it)->get_room_manager()->get_average_room_price() << HOTEL_INFO_DELIMITER << endl;
    }
}

void Output::show_default_price_filter_activation()
{
    cout << DEFAULT_FILTER_ACTIVATION << endl;
}

void Output::show_comments(_comments comments)
{
    for (auto it = comments.begin(); it != comments.end(); it++)
        cout << (*it).user->get_username() << COLON << (*it).comment << endl;
}

void Output::show_average_ratings(Rating* rating)
{
    cout << setprecision(DEFUALT_PRECISION) << fixed;
    cout << LOCATION << rating->get_ratings()[location] << endl;
    cout << CLEANLINESS << rating->get_ratings()[cleanliness] << endl;
    cout << STAFF << rating->get_ratings()[staff] << endl;
    cout << FACILITIES << rating->get_ratings()[facilities] << endl;
    cout << VALUE_FOR_MONEY << rating->get_ratings()[value_for_money] << endl;
    cout << OVERALL << rating->get_ratings()[overall_rating] << endl;
}

void Output::show_reservations(_reservations reservations)
{
    for (auto it = reservations.begin(); it != reservations.end(); it++)
    {
        cout << RESERVATION_ID << (*it)->get_id() << RESERVATION_INFO_DELIMITER;
        cout << RESERVATION_HOTEL_ID << (*it)->get_hotel_id() << RESERVATION_INFO_DELIMITER;
        cout << RESERVATION_ROOM_TYPE << (*it)->get_room_type() << RESERVATION_INFO_DELIMITER;
        cout << RESERVATION_QUANTITY << (*it)->get_quantity() << RESERVATION_INFO_DELIMITER;
        cout << RESERVATION_COST << int((*it)->get_price()) << RESERVATION_INFO_DELIMITER;
        cout << RESERVATION_CHECK_IN << (*it)->get_check_in() << RESERVATION_INFO_DELIMITER;
        cout << RESERVATION_CHECK_OUT << (*it)->get_check_out();
        cout << endl;
    } 
}

void Output::show_reserved_rooms_ids(_room_ids reserved_rooms)
{   
    cout << reserved_rooms[0];
    for (auto it = reserved_rooms.begin() + 1; it != reserved_rooms.end(); it++)
        cout << ROOM_ID_DELIMITER << (*it);
    cout << endl;
}

void Output::show_hotel_info(Hotel* hotel)
{
    cout << setprecision(DEFUALT_PRECISION) << fixed;
    cout << hotel->get_unique_id() << endl;
    cout << hotel->get_properties().name << endl;
    cout << HOTEL_STAR << hotel->get_properties().rating << endl;
    cout << HOTEL_OVERVIEW << hotel->get_properties().hotel_overview << endl;
    cout << HOTEL_AMENITIES << hotel->get_properties().amenities << endl;
    cout << HOTEL_CITY << hotel->get_location().city << endl;
    cout << HOTEL_LATITUDE << hotel->get_location().latitude << endl;
    cout << HOTEL_LONGITUDE << hotel->get_location().longitude << endl;
    cout << HOTEL_ROOOM_NUMBERS << get_room_numbers(hotel->get_room_manager()->get_room_numbers()) << endl;
    cout << HOTEL_ROOM_PRICES << get_room_prices(hotel->get_room_manager()->get_room_prices()) << endl;
}

string Output::get_room_prices(RoomInfo room_prices)
{
    string prices = EMPTY_STRING;
    for (auto it = room_prices.begin(); it != room_prices.end(); it++)
        prices += to_string((*it).second) + ROOM_INFO_DELIMITER;
    prices.erase(prices.size() - 1);
    return prices;
}

string Output::get_room_numbers(RoomInfo room_numbers)
{
    string numbers = EMPTY_STRING;
    for (auto it = room_numbers.begin(); it != room_numbers.end(); it++)
        numbers += to_string((*it).second) + ROOM_INFO_DELIMITER;
    numbers.erase(numbers.size() - 1);
    return numbers;
}

void Output::show_transactions(_transactions transactions, int count)
{
    int i = 0;
    for (auto it = transactions.begin(); it != transactions.end() && i < count ; it++, i++)
        cout << int(*it) << endl;
}

void Output::ok_request()
{
    cout << OK_REQUEST_RESPONSE << endl;
}