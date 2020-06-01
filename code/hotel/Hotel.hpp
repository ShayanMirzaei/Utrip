#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>
#include "Rating.hpp"
#include <vector>

class RoomManager;
class User;
typedef std::vector<Rating*> _ratings; 


struct HotelProperties {
    HotelProperties(std::string _name, int _rating, std::string _hotel_overview, std::string _amenities);
    HotelProperties() {};
    std::string name;
    int rating;
    std::string hotel_overview;
    std::string amenities;
};

struct HotelLocation {
    HotelLocation(std::string _city, double _latitude, double longitude);
    HotelLocation() {};
    std::string city;
    double latitude;
    double longitude;
};

struct Comment {
    Comment(User* _user, std::string _comment);
    User* user;
    std::string comment;
};
typedef std::vector<Comment> _comments;

class Hotel {
    public:
    Hotel(std::string _unique_id, HotelProperties _properties, HotelLocation _location, std::string _image_url, RoomManager* _room_manager);
    ~Hotel();
    HotelProperties get_properties() { return properties; }
    HotelLocation get_location() { return location; }
    std::string get_unique_id() { return unique_id; }
    RoomManager* get_room_manager() { return room_manager; }
    void add_comment(Comment comment);
    void add_rating(Rating* rating);
    _comments get_comments() { return comments; }
    Rating get_average_ratings();

    private:
    std::string unique_id;
    HotelProperties properties;
    HotelLocation location;
    std::string image_url;
    RoomManager* room_manager;
    _comments comments;
    _ratings ratings; 
    Rating total_ratings;

};



#endif 