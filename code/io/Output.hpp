#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <vector>
#include <map>
#include <string>

class Hotel;
class Reservation;
struct Comment;
class Rating;
typedef std::vector<double> _transactions;
typedef std::map<int,int> RoomInfo;
typedef std::vector<std::string> _room_ids;
typedef std::vector<Reservation*> _reservations;
typedef std::vector<Comment> _comments;
typedef std::vector<Hotel*> _hotels;

class Output {
    public:
    void ok_request();
    void show_transactions(_transactions transactions, int count);
    void show_hotel_info(Hotel* hotel);
    void show_reserved_rooms_ids(_room_ids reserved_rooms);
    void show_reservations(_reservations reservations);
    void show_average_ratings(Rating rating);
    void show_comments(_comments comments);
    void show_hotels(_hotels hotels);
    
    private:
    std::string get_room_numbers(RoomInfo room_numbers);
    std::string get_room_prices(RoomInfo room_prices);
};

#endif