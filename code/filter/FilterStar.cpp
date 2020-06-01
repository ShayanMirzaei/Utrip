#include "FilterStar.hpp"
#include "Filter.hpp"
#include <string>
#include <vector>
#include "../hotel/Hotel.hpp"
#include "../Exception.hpp"

#define MIN_STAR_INDEX 0
#define MAX_STAR_INDEX 1

using namespace std;

FilterStar::FilterStar(int min, int max)
{
    min_star = min;
    max_star = max;
    filter_type = FilterType::star;
}

_hotels FilterStar::meet_criteria(_hotels hotels)
{
    _hotels filtered_hotels;
    for (auto it = hotels.begin(); it != hotels.end(); it++)
        if ((*it)->get_properties().rating >= min_star && (*it)->get_properties().rating <= max_star)
            filtered_hotels.push_back(*it);
    return filtered_hotels;
}
