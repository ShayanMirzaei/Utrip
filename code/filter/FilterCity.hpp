#ifndef FILTER_CITY_HPP
#define FILTER_CITY_HPP

#include <vector>
#include <string>
#include "Filter.hpp"

class FilterCity : public Filter {
    public:
    FilterCity(std::string _city);
    _hotels meet_criteria(_hotels hotels);

    private:
    std::string city;
};

#endif