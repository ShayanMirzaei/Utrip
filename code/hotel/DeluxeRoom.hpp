#ifndef DELUXE_ROOM_HPP
#define DELUXE_ROOM_HPP

#include "Room.hpp"

class DeluxeRoom : public Room {
    public:
    DeluxeRoom(int _price);
    int get_next_id();
    void reset_id();

    private:
    static int current_id;
};

#endif