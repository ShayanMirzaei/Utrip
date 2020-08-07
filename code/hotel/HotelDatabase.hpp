#ifndef HOTELDATABASE_HPP
#define HOTELDATABASE_HPP

#include <vector>
#include <string>

class Hotel;
typedef std::vector<Hotel*> _hotels;


class HotelDatabase {
    public:
    ~HotelDatabase();
    void add_hotel(std::vector<std::string> data);
    Hotel* get_hotel_by_id(std::string id);
    _hotels get_hotels() { return hotels; }
    void sort_by_unique_id();
    void add_ratings(std::vector<std::string> data);
    
    private:
    _hotels hotels;
    static bool sort_by_id(Hotel* a, Hotel* b);
    
};

#endif