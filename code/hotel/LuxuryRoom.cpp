#include "Room.hpp"
#include "LuxuryRoom.hpp"
#include <iostream>

using namespace std;

int LuxuryRoom::current_id = 0;

LuxuryRoom::LuxuryRoom(int _price)
{
    type = luxury;
    price = _price;
    id = "l" + to_string(get_next_id());
}

void LuxuryRoom::reset_id()
{
    current_id = 0;
}

int LuxuryRoom::get_next_id()
{
    return ++current_id;
}