#ifndef RATING_HPP
#define RATING_HPP

#include <vector>

class User;
enum RatingType {location, cleanliness, staff, facilities, value_for_money, overall_rating};
typedef std::vector<long double> _weights;

class Rating {
    public:
    Rating(double _location, double _cleanliness, double _staff, double _facilities, double _value_for_money, double _overall_rating);
    double get_overall_rating() { return ratings[overall_rating]; }
    bool overall_rating_is_lower(Rating* rating) { return ratings[overall_rating] < rating->ratings[overall_rating]; }
    double get_weighted_rating_sum(_weights weights);
    std::vector<double> get_ratings() { return ratings; }

    private:
    std::vector<double> ratings;
};

#endif