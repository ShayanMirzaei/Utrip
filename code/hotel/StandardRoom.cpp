#include "Room.hpp"
#include "StandardRoom.hpp"
#include <iostream>

using namespace std;

int StandardRoom::current_id = 0;

StandardRoom::StandardRoom(int _price)
{
    type = standard;
    price = _price;
    id = "s" + to_string(get_next_id());
}

void StandardRoom::reset_id()
{
    current_id = 0;
}

int StandardRoom::get_next_id()
{
    return ++current_id;
}