#ifndef FILTER_HPP
#define FILTER_HPP

#include <vector>
#include <string>

class Hotel;
typedef std::vector<Hotel*> _hotels;
enum FilterType {city , price, star, room, default_price};

class Filter {
    public:
    virtual _hotels meet_criteria(_hotels hotels) = 0;
    bool is_same(Filter* filter);

    protected:
    FilterType filter_type;
};

#endif