#ifndef FILTER_DEFAULT_PRICE_HPP
#define FILTER_DEFAULT_PRICE_HPP

#include "Filter.hpp"
#include <vector>
#include <string>

class Reservation;
typedef std::vector<Reservation*> _reservations;

class FilterDefaultPrice : public Filter {
    public:
    FilterDefaultPrice(_reservations _reservations);
    _hotels meet_criteria(_hotels hotels);

    private:
    _reservations reservations;
    double deviation;
    double average;
    void calculate_average();
    void calculate_deviation();
    int calculate_number_of_rooms();
};

#endif