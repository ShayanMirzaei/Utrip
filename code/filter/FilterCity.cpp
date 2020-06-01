#include "Filter.hpp"
#include "FilterCity.hpp"
#include <vector>
#include <string>
#include "../hotel/Hotel.hpp"

#define CITY_INDEX 0

using namespace std;

FilterCity::FilterCity(string _city)
{
    city = _city;
    filter_type = FilterType::city;
}

_hotels FilterCity::meet_criteria(_hotels hotels)
{
    _hotels filtered_hotels;
    for (auto it = hotels.begin(); it != hotels.end(); it++)
        if ((*it)->get_location().city == city)
            filtered_hotels.push_back(*it);
    return filtered_hotels;
}