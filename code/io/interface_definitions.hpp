#ifndef INTERFACE_DEFINITIONS_HPP
#define INTERFACE_DEFINITIONS_HPP

#define SIGNUP_COMMAND "signup"
#define LOGIN_COMMAND "login"
#define LOGOUT_COMMAND "logout"
#define WALLET_COMMAND "wallet"
#define HOTEL_COMMAND "hotels"
#define RESERVE_COMMAND "reserves"
#define COMMENT_COMMAND "comments"
#define RATING_COMMAND "ratings"
#define FILTER_COMMAND "filters"
#define DEFAULT_PRICE_FILTER_COMMAND "default_price_filter"
#define SORT_COMMAND "sort"
#define MANUAL_WEIGHTS_COMMAND "manual_weights"
#define ESTIMATED_WEIGHTS_COMMAND "estimated_weights"

#define SIGNUP_COMMAND_MINIMUM_WORDS 9
#define LOGIN_COMMAND_MINIMUM_WORDS 7
#define WALLET_COMMAND_MINIMUN_WORDS 5
#define POST_RESERVES_MINIMUM_WORDS 13
#define POST_COMMENT_COMMAND_MINIMUM_WORDS 7
#define POST_RATING_COMMAND_MINIMUM_WORDS 17
#define GET_COMMENT_COMMAND_MINIMUM_WORDS 5
#define GET_RATINGS_COMMAND_MINIMUM_WORDS 5
#define MINIMUM_COMMAND_WORDS 2

#define COMMAND_WITHOUT_ARGUMENT_SIZE 2
#define COMMAND_TYPE_INDEX 0
#define QUESTION_MARK_INDEX 2
#define COMMAND_INDEX 1

#define COMMAND_LINE_DELIMITER ' '
#define QUESTION_MARK "?"

#define POST_REQUEST "POST"
#define GET_REQUEST "GET"
#define DELETE_REQUEST "DELETE"

#define USERNAME "username"
#define EMAIL "email"
#define PASSWORD "password"
#define AMOUNT "amount"
#define COUNT "count"
#define ID "id"
#define HOTEL "hotel"
#define ROOM_TYPE "type"
#define QUANTITY "quantity"
#define CHECK_IN "check_in"
#define CHECK_OUT "check_out"
#define COMMENT "comment"
#define LOCATION "location"
#define CLEANLINESS "cleanliness"
#define STAFF "staff"
#define FACILITIES "facilities"
#define VALUE_FOR_MONEY "value_for_money"
#define OVERALL "overall_rating"
#define CITY "city"
#define MIN_STAR "min_star"
#define MAX_STAR "max_star"
#define MIN_PRICE "min_price"
#define MAX_PRICE "max_price"
#define ACTIVE "active"
#define PROPERTY "property"
#define ORDER "order"

#define TRUE "true"
#define FALSE "false"
#define ASCENDING "ascending"
#define DESCENDING "descending"

#define LOGGED_OUT NULL

#endif