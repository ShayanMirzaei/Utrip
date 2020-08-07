#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>
#include "Rating.hpp"
#include <vector>
#include <map>
#include "RoomManager.hpp"

class Weight;
class User;
typedef std::map<User*, Rating*> _user_ratings; 


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
    void add_rating(User* user, Rating* rating);
    _comments get_comments() { return comments; }
    Rating* get_average_ratings() { return average_ratings; }
    void set_average_rating(Rating* _rating) { average_ratings = _rating; }
    bool id_is_smaller(Hotel* hotel) { return unique_id < hotel->unique_id; }
    bool name_is_smaller(Hotel* hotel) { return properties.name < hotel->properties.name; }
    bool city_is_smaller(Hotel* hotel) { return location.city < hotel->location.city; }
    bool room_price_is_lower(Hotel* hotel, RoomType type);
    bool average_price_is_lower(Hotel* hotel) { return room_manager->get_average_room_price() < hotel->room_manager->get_average_room_price(); }
    bool overall_rating_is_lower(Hotel* hotel) { return average_ratings->overall_rating_is_lower(hotel->average_ratings); }
    bool star_is_lower(Hotel* hotel) { return properties.rating < hotel->properties.rating; }
    double calculate_weighted_rating(Weight* weight);
    std::string get_image_url() { return image_url; }

    private:
    std::string unique_id;
    HotelProperties properties;
    HotelLocation location;
    std::string image_url;
    RoomManager* room_manager;
    _comments comments;
    _user_ratings ratings; 
    Rating* average_ratings;

};



#endif 