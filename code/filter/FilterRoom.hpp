#ifndef FILTER_ROOM_HPP
#define FILTER_ROOM_HPP

#include "Filter.hpp"
#include <string>

class FilterRoom : public Filter {
    public:
    FilterRoom(std::string _room_type, int _quantity, int _check_in, int _check_out);
    _hotels meet_criteria(_hotels hotels);

    private:
    std::string room_type;
    int quantity;
    int check_in;
    int check_out;

};

#endif