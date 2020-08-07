#ifndef WEIGHT_HPP
#define WEIGHT_HPP

#include <vector>
#include "../hotel/Rating.hpp"

typedef std::vector<Rating*> _ratings;
typedef std::vector<long double> _weights;
typedef std::vector<long double> _derivatives;

class Weight {
    public:
    Weight(long double location_weight, long double cleanliness_weight, long double staff_weight, long double facilities_weight, long double value_for_money_weight);
    Weight();
    void calculate_weights(_ratings ratings);
    _weights get_weights() { return weights; }
    long double calculate_weighted_average(_weights weights_to_derive, Rating* rating);
    long double calculate_weighted_average(Rating* rating);

    private:
    _weights weights;
    _derivatives derivatives;
    long double total_weight;
    long double error_function(_weights weights_to_derive ,Rating* rating);
    void reset_derivatives();
    void set_derivatives();
    void calculate_derivatives(_ratings ratings);
    long double calculate_derivative(int weight_index, Rating* rating);
    long double calculate_total_weight(_weights _weights);
    _weights add_to_weight(int weight_index, long double amount);
    void calculate_new_weights();
    void clamp_weights();
};


#endif