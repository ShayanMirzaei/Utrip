#include "Filter.hpp"
#include "FilterRoom.hpp"
#include "../hotel/Hotel.hpp"
#include "../hotel/RoomManager.hpp"
#include <string>
#include <vector>

using namespace std;

FilterRoom::FilterRoom(string _room_type, int _quantity, int _check_in, int _check_out)
{
    room_type = _room_type;
    quantity = _quantity;
    check_in = _check_in;
    check_out = _check_out;
    filter_type = FilterType::room;
}

_hotels FilterRoom::meet_criteria(_hotels hotels)
{
    _hotels filtered_hotels;
    for (auto it = hotels.begin(); it != hotels.end(); it++)
        if ((*it)->get_room_manager()->has_available_rooms(room_type, quantity, check_in, check_out))
            filtered_hotels.push_back(*it);
    return filtered_hotels;
}