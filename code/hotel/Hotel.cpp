#include "Hotel.hpp"
#include "RoomManager.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "../user/User.hpp"
#include "Rating.hpp"
#include "../user/Weight.hpp"
#include "../Exception.hpp"

#define INIT_VALUE 0.0

using namespace std;

HotelProperties::HotelProperties(string _name, int _rating, string _hotel_overview, string _amenities)
{
    name = _name;
    rating = _rating;
    hotel_overview = _hotel_overview;
    amenities = _amenities;
}

HotelLocation::HotelLocation(string _city, double _latitude, double _longitude)
{
    city = _city;
    latitude = _latitude;
    longitude = _longitude;
}

Comment::Comment(User* _user, string _comment)
{
    user = _user;
    comment = _comment;
}

Hotel::Hotel(string _unique_id, HotelProperties _properties, HotelLocation _location, string _image_url, RoomManager* _room_manager)
{
    unique_id = _unique_id;
    properties = _properties;
    location = _location;
    image_url = _image_url;
    room_manager = _room_manager;
}

Hotel::~Hotel()
{
    delete room_manager;
    for (auto it = ratings.begin(); it != ratings.end(); it++)
    {
        delete (*it).second;
        (*it).second = nullptr;
    }
}

double Hotel::calculate_weighted_rating(Weight* weight)
{
    double weighted_rating = weight->calculate_weighted_average(average_ratings);
    return weighted_rating;
}

bool Hotel::room_price_is_lower(Hotel* hotel, RoomType type)
{
    return room_manager->room_price_is_lower(hotel->room_manager, type);
}

void Hotel::add_rating(User* user, Rating* rating)
{   
    ratings[user] = rating;
}

void Hotel::add_comment(Comment comment)
{
    comments.push_back(comment);
}
