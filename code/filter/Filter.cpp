#include "Filter.hpp"

using namespace std;

bool Filter::is_same(Filter* filter)
{
    if (filter_type == filter->filter_type)
        return true;
    return false;
}