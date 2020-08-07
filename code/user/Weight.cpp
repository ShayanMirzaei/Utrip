#include "Weight.hpp"
#include <cstdlib>
#include "../hotel/Rating.hpp"
#include <math.h>
#include <iostream>

#define WEIGHT_RANGE_MAX 400
#define WEIGHT_RANGE_MIN 100
#define TO_FLOAT 100
#define WEIGHT_COUNT 5
#define DERIVATIVE_COUNT 5
#define EPSILON 1e-4
#define ALPHA 1
#define MINIMUM_WEIGHT 1
#define MAXIMUM_WEIGHT 5
#define ITERATIONS 1000

using namespace std;

typedef vector<Rating*> _ratings;
typedef vector<long double> _derivatives;
typedef vector<long double> _weights;

Weight::Weight(long double location_weight, long double cleanliness_weight, long double staff_weight, long double facilities_weight, long double value_for_money_weight)
{
    weights.push_back(location_weight);
    weights.push_back(cleanliness_weight);
    weights.push_back(staff_weight);
    weights.push_back(facilities_weight);
    weights.push_back(value_for_money_weight);
    total_weight = location_weight + cleanliness_weight + staff_weight + facilities_weight + value_for_money_weight;
}

Weight::Weight()
{
    total_weight = 0.0;
    srand(time(0));
    for (int i = 0; i < WEIGHT_COUNT; i++)
        weights.push_back((double(rand() % WEIGHT_RANGE_MAX + WEIGHT_RANGE_MIN) / TO_FLOAT));
    for (int i = 0; i < WEIGHT_COUNT; i++)
        total_weight += weights[i];
    set_derivatives();
}

void Weight::calculate_weights(_ratings ratings)
{
    int iterator = 0;
    while (iterator < ITERATIONS)
    {
        iterator++;
        reset_derivatives();
        calculate_derivatives(ratings);
        calculate_new_weights();
    }
}

void Weight::calculate_new_weights()
{
    for (int i = 0; i < DERIVATIVE_COUNT; i++)
        weights[i] -= ALPHA * derivatives[i];
    clamp_weights();
}

void Weight::clamp_weights()
{
    for (int i = 0; i < WEIGHT_COUNT; i++)
        if (weights[i] < MINIMUM_WEIGHT)
            weights[i] = MINIMUM_WEIGHT;
        else if (weights[i] > MAXIMUM_WEIGHT)
            weights[i] = MAXIMUM_WEIGHT;
}

void Weight::calculate_derivatives(_ratings ratings)
{
    for (auto it = ratings.begin(); it != ratings.end(); it++)
        for (int i = 0; i < DERIVATIVE_COUNT; i++)
                derivatives[i] += calculate_derivative(i, *it);
}

long double Weight::calculate_derivative(int weight_index, Rating* rating)
{
    long double derivative = error_function(add_to_weight(weight_index, EPSILON), rating) - error_function(weights, rating);
    return derivative / EPSILON;
}

_weights Weight::add_to_weight(int weight_index,long double amount)
{
    _weights new_weights = weights;
    new_weights[weight_index] += amount;
    return new_weights;
}

void Weight::reset_derivatives()
{
    for (int i = 0; i < derivatives.size(); i++)
        derivatives[i] = 0;
}

long double Weight::error_function(_weights weights_to_derive ,Rating* rating)
{
    long double error = calculate_weighted_average(weights_to_derive, rating) - rating->get_overall_rating();
    return pow(error, 2);
}

long double Weight::calculate_weighted_average(_weights weights_to_derive, Rating* rating)
{ 
    long double weighted_average = rating->get_weighted_rating_sum(weights_to_derive);
    weighted_average /= calculate_total_weight(weights_to_derive);
    return weighted_average;
}

long double Weight::calculate_weighted_average(Rating* rating)
{
    return calculate_weighted_average(weights, rating);
}

long double Weight::calculate_total_weight(_weights _weights)
{
    long double total = 0.0;
    for (auto it = _weights.begin(); it != _weights.end(); it++)
        total += *it;
    return total;
}

void Weight::set_derivatives()
{
    for (int i = 0; i < DERIVATIVE_COUNT; i++)
        derivatives.push_back(1);
}