#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP

#include <vector>
#include <string>
#include <map>
#include "Room.hpp"

class Room;
typedef std::vector<Room*> _rooms;
typedef std::vector<std::string> _room_data;
typedef std::map<int,int> RoomInfo;
typedef std::vector<std::string> _room_ids;

class RoomManager {
    public:
    RoomManager(_room_data room_data);
    ~RoomManager();
    RoomInfo get_room_numbers() { return room_numbers; }
    RoomInfo get_room_prices() { return room_prices; }
    double get_average_room_price();
    double get_reservation_one_night_price(std::string room_type, int quantity);
    Reservation* reserve_rooms(std::string room_type, int quantity, int check_in, int check_out);
    void cancel_reservation(Reservation* reservation);
    bool has_available_rooms(std::string room_type, int quantity, int check_in, int check_out);
    int get_total_number_of_rooms() { return rooms.size(); }
    bool room_price_is_lower(RoomManager* room_manager, RoomType type);
    
    private:
    _rooms rooms;
    RoomInfo room_numbers;
    RoomInfo room_prices;
    void add_rooms(_room_data room_data);
    void reset_room_ids();
    void set_room_numbers(_room_data room_data);
    void set_room_prices(_room_data room_data);
    RoomType get_room_type(std::string room_type);
    void check_enough_rooms(int reserved_rooms, int quantity);
    _room_ids find_available_rooms(RoomType type, int quantity, int check_in, int check_out);
    void add_reservation_to_rooms(Reservation* reservation, _room_ids room_ids);


};

#endif