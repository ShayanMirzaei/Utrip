#include "Room.hpp"
#include "PremiumRoom.hpp"
#include <iostream>

using namespace std;

int PremiumRoom::current_id = 0;

PremiumRoom::PremiumRoom(int _price)
{
    type = premium;
    price = _price;
    id = "p" + to_string(get_next_id());
}

void PremiumRoom::reset_id()
{
    current_id = 0;
}

int PremiumRoom::get_next_id()
{
    return ++current_id;
}