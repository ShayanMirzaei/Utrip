#ifndef FILTER_PRICE_HPP
#define FILTER_PRICE_HPP

#include "Filter.hpp"
#include <vector>
#include <string>

class FilterPrice : public Filter {
    public:
    FilterPrice(double min, double max);
    _hotels meet_criteria(_hotels hotels);

    private:
    double min_price;
    double max_price;

};

#endif