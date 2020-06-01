#ifndef PREMIUM_ROOM_HPP
#define PREMIUM_ROOM_HPP

#include "Room.hpp"

class PremiumRoom : public Room {
    public:
    PremiumRoom(int _price);
    int get_next_id();
    void reset_id();

    private:
    static int current_id;
};

#endif