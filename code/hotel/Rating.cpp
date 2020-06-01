#include "Rating.hpp"

using namespace std;

Rating::Rating(User* _user, double _location, double _cleanliness, double _staff, double _facilities, double _value_for_money, double _overall_rating)
{
    user = _user;
    location = _location;
    cleanliness = _cleanliness;
    staff = _staff;
    facilities = _facilities;
    value_for_money = _value_for_money;
    overall_rating = _overall_rating;
}

Rating::Rating() {};

Rating::~Rating()
{
    user = nullptr;
}

Rating Rating::operator+(Rating rating)
{
    location = location + rating.location;
    cleanliness = cleanliness + rating.cleanliness;
    staff = staff + rating.staff;
    facilities = facilities + rating.facilities;
    value_for_money = value_for_money + rating.value_for_money;
    overall_rating = overall_rating + rating.overall_rating;
    return *this;
}

Rating Rating::operator/(double num)
{
    location = location / num;
    cleanliness = cleanliness / num; 
    staff = staff / num; 
    facilities = facilities / num; 
    value_for_money = value_for_money / num; 
    overall_rating = overall_rating / num; 
    return *this;
}