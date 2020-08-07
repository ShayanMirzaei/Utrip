#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <vector>
#include <map>
#include <string>

class Hotel;
class Reservation;
struct Comment;
class Rating;
class Weight;
typedef std::vector<double> _transactions;
typedef std::map<int,int> RoomInfo;
typedef std::vector<std::string> _room_ids;
typedef std::vector<Reservation*> _reservations;
typedef std::vector<Comment> _comments;
typedef std::vector<Hotel*> _hotels;
typedef std::vector<long double> _weights;

class Output {
    public:
    void ok_request();
    void show_transactions(_transactions transactions, int count);
    void show_hotel_info(Hotel* hotel);
    void show_reserved_rooms_ids(_room_ids reserved_rooms);
    void show_reservations(_reservations reservations);
    void show_average_ratings(Rating* rating);
    void show_comments(_comments comments);
    void show_hotels(_hotels hotels);
    void show_default_price_filter_activation();
    void show_manual_weights(Weight* weight, std::string mode);
    void show_estimated_weights(Weight* weight);
    
    private:
    std::string get_room_numbers(RoomInfo room_numbers);
    std::string get_room_prices(RoomInfo room_prices);
    void show_weights(_weights weights);
};

#endif