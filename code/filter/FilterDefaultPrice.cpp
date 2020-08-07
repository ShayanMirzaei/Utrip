#include "Filter.hpp"
#include "FilterDefaultPrice.hpp"
#include "../hotel/Hotel.hpp"
#include "../hotel/RoomManager.hpp"
#include <string>
#include <vector>
#include "../hotel/Reservation.hpp"
#include <math.h>
#include <iostream>

using namespace std;

FilterDefaultPrice::FilterDefaultPrice(_reservations _reservations)
{
    reservations = _reservations;
    calculate_average();
    calculate_deviation();
    filter_type = FilterType::default_price;
}

void FilterDefaultPrice::calculate_deviation()
{
    deviation = 0.0;
    for (auto it = reservations.begin(); it != reservations.end(); it++)
        deviation += (pow((((*it)->get_one_night_price() / (*it)->get_quantity()) - average), 2) * (*it)->get_quantity());
    deviation /= (calculate_number_of_rooms() - 1);
    deviation = sqrt(deviation);
}

void FilterDefaultPrice::calculate_average()
{
    average = 0;
    int number_of_rooms = calculate_number_of_rooms();
    for (auto it = reservations.begin(); it != reservations.end(); it++)
        average += (*it)->get_one_night_price();
    average /= number_of_rooms;  
}

int FilterDefaultPrice::calculate_number_of_rooms()
{
    int number_of_rooms = 0;
    for (auto it = reservations.begin(); it != reservations.end(); it++)
        number_of_rooms += (*it)->get_quantity();
    return number_of_rooms;
}

_hotels FilterDefaultPrice::meet_criteria(_hotels hotels)
{
    _hotels filtered_hotels;
    for (auto it = hotels.begin(); it != hotels.end(); it++)
        if (abs((*it)->get_room_manager()->get_average_room_price() - average) <= 2 * deviation)
            filtered_hotels.push_back(*it);
    return filtered_hotels;
}