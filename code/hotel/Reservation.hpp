#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>
#include <vector>

typedef std::vector<std::string> _room_ids;

class Reservation {
    public:
    Reservation(int _check_in, int _check_out, _room_ids _reserved_rooms, double _total_price, std::string _room_type, int _quantity);
    ~Reservation();
    bool is_full(int new_check_in, int new_check_out);
    void set_hotel_id(std::string _hotel_id);
    _room_ids get_room_ids() { return reserved_room; }
    double get_price() { return total_price; }
    void set_id(int _id) { reservation_id = _id; }
    int get_id() { return reservation_id; }
    std::string get_hotel_id() { return hotel_id; }
    std::string get_room_type() { return room_type; }
    int get_check_in() { return check_in; }
    int get_check_out() { return check_out; }
    int get_quantity() { return quantity; }
    double get_one_night_price();

    private:
    int reservation_id;
    std::string hotel_id;
    std::string room_type;
    int quantity;
    int check_in;
    int check_out;
    double total_price;
    _room_ids reserved_room;

};

#endif