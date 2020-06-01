#include "FilterPrice.hpp"
#include "Filter.hpp"
#include <string>
#include <vector>
#include "../hotel/Hotel.hpp"
#include "../hotel/RoomManager.hpp"
#include "../Exception.hpp"

#define MIN_PRICE_INDEX 0
#define MAX_PRICE_INDEX 1

using namespace std;

FilterPrice::FilterPrice(double min, double max)
{
    min_price = min;
    max_price = max;
    filter_type = FilterType::price; 
}

_hotels FilterPrice::meet_criteria(_hotels hotels)
{
    _hotels filtered_hotels;
    for (auto it = hotels.begin(); it != hotels.end(); it++)
        if ((*it)->get_room_manager()->get_average_room_price() >= min_price && (*it)->get_room_manager()->get_average_room_price() <= max_price)
            filtered_hotels.push_back(*it);
    return filtered_hotels;
}
