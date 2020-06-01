#ifndef FILTER_STAR_HPP
#define FILTER_STAR_HPP

#include "Filter.hpp"
#include <vector>
#include <string>

class FilterStar : public Filter {
    public:
    FilterStar(int min, int max);
    _hotels meet_criteria(_hotels hotels);

    private:
    int min_star;
    int max_star;
};

#endif