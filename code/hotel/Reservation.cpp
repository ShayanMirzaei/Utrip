#include "Reservation.hpp"
#include <string>
#include <iostream>

using namespace std;

Reservation::Reservation(int _check_in, int _check_out, _room_ids _reserved_rooms, double _total_price, string _room_type, int _quantity)
{
    check_in = _check_in;
    check_out = _check_out;
    reserved_room = _reserved_rooms;
    total_price = _total_price;
    room_type = _room_type;
    quantity = _quantity;
}

void Reservation::set_hotel_id(string _hotel_id)
{
    hotel_id = _hotel_id;
}

bool Reservation::is_full(int new_check_in, int new_check_out)
{
    if ((new_check_in <= check_out && new_check_in >= check_in) || (new_check_out >= check_in && new_check_out <= check_out))
        return true;
    return false;
}