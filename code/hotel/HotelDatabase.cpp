#include "HotelDatabase.hpp"
#include "Hotel.hpp"
#include "RoomManager.hpp"
#include <string>
#include <vector>
#include "../Exception.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

enum HotelData {id, name, rating, overview, amenities, city, latitude, longitude, image_url};
typedef vector<Room*> _rooms;

HotelDatabase::~HotelDatabase()
{
    for (auto it = hotels.begin(); it != hotels.end(); it++)
    {
        delete *it;
        *it = nullptr;
    }
}

void HotelDatabase::add_hotel(vector<string> data)
{
    HotelProperties properties(data[name], stoi(data[rating]), data[overview], data[amenities]);
    HotelLocation location(data[city], stod(data[latitude]), stod(data[longitude]));
    RoomManager* room_manager = new RoomManager(data);
    Hotel* new_hotel = new Hotel(data[id], properties, location, data[image_url], room_manager);
    hotels.push_back(new_hotel);
}

Hotel* HotelDatabase::get_hotel_by_id(string id)
{
    for (auto it = hotels.begin(); it != hotels.end(); it++)
            if ((*it)->get_unique_id() == id)
                return *it;
    throw NotFound();
}

bool HotelDatabase::sort_by_id(Hotel* a, Hotel* b)
{
    return a->get_unique_id() < b->get_unique_id();
}

void HotelDatabase::sort_by_unique_id()
{
    sort(hotels.begin(), hotels.end(), sort_by_id);
}