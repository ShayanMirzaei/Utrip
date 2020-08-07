#include "Room.hpp"
#include "Reservation.hpp"
#include <iostream>

using namespace std;

Room::~Room()
{
    for (auto it = reservations.begin(); it != reservations.end(); it++)
    {
        //delete *it;
        *it = nullptr;
    }
}

bool Room::is_available(RoomType room_type, int check_in, int check_out)
{
    if (type != room_type)
        return false;
    for (auto it = reservations.begin(); it != reservations.end(); it++)
        if ((*it)->is_full(check_in, check_out))
            return false;
    return true;
}

void Room::cancel_reservation(Reservation* reservation)
{
    for (auto it = reservations.begin(); it != reservations.end(); it++)
        if ((*it) == reservation)
            {
                reservations.erase(it);
                break;
            }
}

void Room::add_reservation(Reservation* reservation)
{
    reservations.push_back(reservation);
}