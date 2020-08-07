#ifndef SORT_HPP
#define SORT_HPP

#define ASCENDING false
#define DESCENDING true

#include <string>
#include <vector>
#include <map>

class Hotel;
typedef std::vector<Hotel*> _hotels;
class Weight;
class Rating;
typedef std::map<Hotel*, Rating*> hotel_ratings;

enum SortType {sort_id, sort_name, sort_star, sort_city, sort_standard_room_price, sort_deluxe_room_price, sort_luxury_room_price, sort_premium_room_price, sort_average_room_price, sort_rating_overall, sort_rating_personal};

class Sort {
    public:
    Sort(std::string _type, bool _order);
    void sort_hotels(_hotels& hotels);
    void set_weight(Weight* _weight) { weight = _weight; }
    bool needs_estimated_weights() { return type == sort_rating_personal; }
    void add_ratings(hotel_ratings _ratings) { ratings = _ratings; }

    private:
    SortType type;
    bool order;
    Weight* weight;
    hotel_ratings ratings;
    SortType convert_type(std::string _type);
    bool sort_by(Hotel* a, Hotel* b);
    bool compare_personal_rating(Hotel* a, Hotel* b);
};

#endif