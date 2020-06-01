#include "Hotel.hpp"
#include "RoomManager.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "../user/User.hpp"
#include "Rating.hpp"
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
    total_ratings = Rating(NULL ,INIT_VALUE, INIT_VALUE, INIT_VALUE, INIT_VALUE, INIT_VALUE, INIT_VALUE);
}

Hotel::~Hotel()
{
    delete room_manager;
    for (auto it = ratings.begin(); it != ratings.end(); it++)
    {
        delete *it;
        *it = nullptr;
    }
}

Rating Hotel::get_average_ratings()
{
    if (ratings.size() == 0)
        throw NoRating();
    return total_ratings / ratings.size();
}

void Hotel::add_rating(Rating* rating)
{   
    for (auto it = ratings.begin(); it != ratings.end(); it++)
        if ((*it)->user == rating->user)
        {
            ratings.erase(it);
            break;
        }
    ratings.push_back(rating);
    total_ratings = total_ratings + *rating;
}

void Hotel::add_comment(Comment comment)
{
    comments.push_back(comment);
}
