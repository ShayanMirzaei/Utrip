#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>

enum RoomType {standard, deluxe, luxury, premium};
class Reservation;
typedef std::vector<Reservation*> _reservations;

class Room {
    public:
    ~Room();
    virtual void reset_id() = 0;
    bool is_available(RoomType room_type, int check_in, int check_out);
    std::string get_id() { return id; }
    void add_reservation(Reservation* reservation);
    void cancel_reservation(Reservation* reservation);

    protected:
    RoomType type;
    int price;
    std::string id;
    _reservations reservations;

};

#endif