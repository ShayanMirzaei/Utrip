#ifndef RATING_HPP
#define RATING_HPP

class User;

class Rating {
    public:
    Rating(User* user, double _location, double _cleanliness, double _staff, double _facilities, double _value_for_money, double _overall_rating);
    Rating();
    ~Rating();
    Rating operator+(Rating rating);
    Rating operator/(double num);
    User* user;
    double location;
    double cleanliness;
    double staff;
    double facilities;
    double value_for_money;
    double overall_rating;
};

#endif