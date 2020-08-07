#include "Exception.hpp"

using namespace std;

const char* BadRequest::what() const noexcept
{
    return "Bad Request";
}

const char* NotFound::what() const noexcept
{
    return "Not Found";
}

const char* PermissionDenied::what() const noexcept
{
    return "Permission Denied";
}

const char* EmptyList::what() const noexcept
{
    return "Empty";
}

const char* NotEnoughCredit::what() const noexcept
{
    return "Not Enough Credit";
}

const char* NotEnoughRoom::what() const noexcept
{
    return "Not Enough Room";
}

const char* NoRating::what() const noexcept
{
    return "No Rating";
}

const char* InsufficientRatings::what() const noexcept
{
    return "Insufficient Ratings";
}