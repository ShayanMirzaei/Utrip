#include "Rating.hpp"
#include <vector>

using namespace std;

typedef vector<long double> _weights;

Rating::Rating(double _location, double _cleanliness, double _staff, double _facilities, double _value_for_money, double _overall_rating)
{
    ratings.push_back(_location);
    ratings.push_back(_cleanliness);
    ratings.push_back(_staff);
    ratings.push_back(_facilities);
    ratings.push_back(_value_for_money);
    ratings.push_back(_overall_rating);
}

double Rating::get_weighted_rating_sum(_weights weights)
{
    double sum = 0;
    for (int i = 0; i < weights.size(); i++)
        sum += ratings[i] * weights[i];
    return sum;
}