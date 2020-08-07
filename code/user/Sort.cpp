#include "Sort.hpp"
#include <string>
#include <vector>
#include "../Exception.hpp"
#include "../hotel/Hotel.hpp"
#include <algorithm>
#include <map>
#include "../hotel/RoomManager.hpp"
#include "../hotel/Rating.hpp"
#include <iostream>

#define ID "id"
#define NAME "name"
#define STAR "star_rating"
#define CITY "city"
#define STANDARD_ROOM_PRICE "standard_room_price"
#define DELUXE_ROOM_PRICE "deluxe_room_price"
#define LUXURY_ROOM_PRICE "luxury_room_price"
#define PREMIUM_ROOM_PRICE "premium_room_price"
#define AVERAGE_ROOM_PRICE "average_room_price"
#define RATING_OVERALL "rating_overall"
#define RATING_PERSONAL "rating_personal"
#define HOTEL_IS_ALREADY_RATED 1

using namespace std;

typedef vector<Hotel*> _hotels;
typedef map<int,int> RoomInfo;
typedef map<Hotel*, Rating*> hotel_ratings;

Sort::Sort(string _type, bool _order)
{
    type = convert_type(_type);
    order = _order; 
}

void Sort::sort_hotels(_hotels& hotels)
{
    stable_sort(hotels.begin(), hotels.end(), [&](Hotel* a, Hotel* b)
    {
        return this->sort_by(a, b);
    });
}

bool Sort::sort_by(Hotel* a, Hotel* b)
{
    switch (type)
    {
    case sort_id:
        return a->id_is_smaller(b) ^ order;
    case sort_name:
        return a->name_is_smaller(b) ^ order;
    case sort_star:
        return a->star_is_lower(b) ^ order;
    case sort_city:
        return a->city_is_smaller(b) ^ order;
    case sort_standard_room_price:
        return a->room_price_is_lower(b, standard) ^ order;
    case sort_deluxe_room_price:
        return a->room_price_is_lower(b, deluxe) ^ order;
    case sort_luxury_room_price:
        return a->room_price_is_lower(b, luxury) ^ order;
    case sort_premium_room_price:
        return a->room_price_is_lower(b, premium) ^ order;
    case sort_average_room_price:
        return a->average_price_is_lower(b) ^ order;
    case sort_rating_overall:
        return a->overall_rating_is_lower(b) ^ order;
    case sort_rating_personal:
        return compare_personal_rating(a, b);
    }
}

bool Sort::compare_personal_rating(Hotel* a, Hotel* b)
{
    double a_rating = a->calculate_weighted_rating(weight);
    double b_rating = b->calculate_weighted_rating(weight);
    if (ratings.count(a) == HOTEL_IS_ALREADY_RATED)
        a_rating = ratings[a]->get_overall_rating();
    if (ratings.count(b) == HOTEL_IS_ALREADY_RATED)
        b_rating = ratings[b]->get_overall_rating();
    return (a_rating < b_rating) ^ order;
}

SortType Sort::convert_type(string _type)
{
    if (_type == ID)
        return sort_id;
    else if (_type == NAME)
        return sort_name;
    else if (_type == STAR)
        return sort_star;
    else if (_type == CITY)
        return sort_city;
    else if (_type == STANDARD_ROOM_PRICE)
        return sort_standard_room_price;
    else if (_type == DELUXE_ROOM_PRICE)
        return sort_deluxe_room_price;
    else if (_type == LUXURY_ROOM_PRICE)
        return sort_luxury_room_price;
    else if (_type == PREMIUM_ROOM_PRICE)
        return sort_premium_room_price;
    else if (_type == AVERAGE_ROOM_PRICE)
        return sort_average_room_price;
    else if (_type == RATING_OVERALL)
        return sort_rating_overall;
    else if (_type == RATING_PERSONAL)
        return sort_rating_personal;
    else 
        throw BadRequest();
}