#include "RoomManager.hpp"
#include "Room.hpp"
#include "StandardRoom.hpp"
#include "DeluxeRoom.hpp"
#include "LuxuryRoom.hpp"
#include "PremiumRoom.hpp"
#include <vector>
#include <string>
#include "../Exception.hpp"
#include "Reservation.hpp"
#include <iostream>

#define STANDARD "standard"
#define DELUXE "deluxe"
#define LUXURY "luxury"
#define PREMIUM "premium" 

using namespace std;

enum RoomData {standard_num = 9, deluxe_num, luxury_num, premium_num, standard_price, deluxe_price, luxury_price, premium_price};
typedef vector<Room*> _rooms;
typedef pair<int,int> RoomInfoPair;
typedef std::vector<std::string> _room_ids;

RoomManager::RoomManager(vector<string> room_data)
{
    add_rooms(room_data);
    set_room_numbers(room_data);
    set_room_prices(room_data);
    reset_room_ids();
}

RoomManager::~RoomManager()
{
    for (auto it = rooms.begin(); it != rooms.end(); it++)
    {
        delete *it;
        *it = nullptr;
    }
}

bool RoomManager::room_price_is_lower(RoomManager* room_manager, RoomType type)
{
    switch (type)
    {
    case standard:
        return room_prices[standard] < room_manager->room_prices[standard];
    case deluxe:
        return room_prices[deluxe] < room_manager->room_prices[deluxe];
    case luxury:
        return room_prices[luxury] < room_manager->room_prices[luxury];
    case premium:
        return room_prices[premium] < room_manager->room_prices[premium];
    }
}

double RoomManager::get_reservation_one_night_price(string room_type, int quantity)
{
    double total_price = 0;
    RoomType type = get_room_type(room_type);
    for (int i = 0; i < quantity; i++)
        total_price += room_prices[type];
    return total_price;
}

void RoomManager::cancel_reservation(Reservation* reservation)
{
    for (auto it = rooms.begin(); it != rooms.end(); it++)
        (*it)->cancel_reservation(reservation);
}

Reservation* RoomManager::reserve_rooms(string room_type, int quantity, int check_in, int check_out)
{
    RoomType type = get_room_type(room_type);
    _room_ids reserved_rooms = find_available_rooms(type, quantity, check_in, check_out);
    check_enough_rooms(reserved_rooms.size(), quantity);
    double total_price = get_reservation_one_night_price(room_type, quantity) * (check_out - check_in + 1);
    Reservation* reservation = new Reservation(check_in, check_out, reserved_rooms, total_price, room_type, quantity);
    add_reservation_to_rooms(reservation, reserved_rooms);
    return reservation;
}

bool RoomManager::has_available_rooms(string room_type, int quantity, int check_in, int check_out)
{
    RoomType type = get_room_type(room_type);
    _room_ids available_rooms = find_available_rooms(type, quantity, check_in, check_out);
    if (available_rooms.size() < quantity)
        return false;
    return true;
}

void RoomManager::add_reservation_to_rooms(Reservation* reservation, _room_ids room_ids)
{
    for (auto id_it = room_ids.begin(); id_it != room_ids.end(); id_it++)
        for (auto room_it = rooms.begin(); room_it != rooms.end(); room_it++)
            if ((*room_it)->get_id() == *id_it)
                (*room_it)->add_reservation(reservation);
}

void RoomManager::check_enough_rooms(int reserved_rooms, int quantity)
{
    if (reserved_rooms != quantity)
        throw NotEnoughRoom();
}

_room_ids RoomManager::find_available_rooms(RoomType type, int quantity, int check_in, int check_out)
{
    _room_ids reserved_rooms;
    for (auto it = rooms.begin(); it != rooms.end(); it++)
        if ((*it)->is_available(type, check_in, check_out) && reserved_rooms.size() != quantity)
            reserved_rooms.push_back((*it)->get_id());
    return reserved_rooms;
}

RoomType RoomManager::get_room_type(string room_type)
{
    if (room_type == STANDARD)
        return standard;
    else if (room_type == DELUXE)
        return deluxe;
    else if (room_type == LUXURY)
        return luxury;
    else if (room_type == PREMIUM)
        return premium;
    else 
        throw BadRequest();
}

double RoomManager::get_average_room_price()
{
    double average_price = 0;
    int type_of_rooms = 0;
    for (auto it = room_prices.begin(); it != room_prices.end(); it++)
        if ((*it).second != 0)
        {
            type_of_rooms++;
            average_price += (*it).second;
        }
    if (type_of_rooms == 0)
        return 0;
    return average_price / type_of_rooms;
}

void RoomManager::set_room_numbers(_room_data room_data)
{
    room_numbers.insert(RoomInfoPair(standard, stoi(room_data[standard_num])));
    room_numbers.insert(RoomInfoPair(deluxe, stoi(room_data[deluxe_num])));
    room_numbers.insert(RoomInfoPair(luxury, stoi(room_data[luxury_num])));
    room_numbers.insert(RoomInfoPair(premium, stoi(room_data[premium_num])));
}

void RoomManager::set_room_prices(_room_data room_data)
{
    room_prices.insert(RoomInfoPair(standard, stoi(room_data[standard_price])));
    room_prices.insert(RoomInfoPair(deluxe, stoi(room_data[deluxe_price])));
    room_prices.insert(RoomInfoPair(luxury, stoi(room_data[luxury_price])));
    room_prices.insert(RoomInfoPair(premium, stoi(room_data[premium_price])));
}

void RoomManager::reset_room_ids()
{
    for (auto it = rooms.begin(); it != rooms.end(); it++)
        (*it)->reset_id(); 
}

void RoomManager::add_rooms(vector<string> room_data)
{   
    for (int i = 0; i < stoi(room_data[standard_num]); i++)
        rooms.push_back(new StandardRoom(stoi(room_data[standard_price])));
    for (int i = 0; i < stoi(room_data[deluxe_num]); i++)
        rooms.push_back(new DeluxeRoom(stoi(room_data[deluxe_price])));
    for (int i = 0; i < stoi(room_data[luxury_num]); i++)
        rooms.push_back(new LuxuryRoom(stoi(room_data[luxury_price])));
    for (int i = 0; i < stoi(room_data[premium_num]); i++)
        rooms.push_back(new PremiumRoom(stoi(room_data[premium_price])));
}

