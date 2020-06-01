#ifndef LUXURY_ROOM_HPP
#define LUXURY_ROOM_HPP

#include "Room.hpp"

class LuxuryRoom : public Room {
    public:
    LuxuryRoom(int _price);
    int get_next_id();
    void reset_id();

    private:
    static int current_id;
};

#endif