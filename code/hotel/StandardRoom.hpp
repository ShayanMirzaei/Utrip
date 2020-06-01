#ifndef STANDARD_ROOM_HPP
#define STANDARD_ROOM_HPP

#include "Room.hpp"

class StandardRoom : public Room {
    public:
    StandardRoom(int _price);
    int get_next_id();
    void reset_id();

    private:
    static int current_id;
};

#endif