#include "Room.hpp"
#include "DeluxeRoom.hpp"
#include <iostream>

using namespace std;

int DeluxeRoom::current_id = 0;

DeluxeRoom::DeluxeRoom(int _price)
{
    type = deluxe;
    price = _price;
    id = "d" + to_string(get_next_id());
}

void DeluxeRoom::reset_id()
{
    current_id = 0;
}

int DeluxeRoom::get_next_id()
{
    return ++current_id;
}