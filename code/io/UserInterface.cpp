#include "UserInterface.hpp"
#include "../Utrip.hpp"
#include "../utilities.hpp"
#include "../Exception.hpp"
#include <string>
#include <iostream>
#include <map>
#include "interface_definitions.hpp"

using namespace std;

typedef vector<string> CommandLine;

UserInterface::UserInterface(Utrip* _utrip)
{
    utrip = _utrip;
    logged_in_user = NULL;
}

UserInterface::~UserInterface()
{
    utrip = nullptr;
    logged_in_user = nullptr;
}

string UserInterface::get_arguement(string field_name)
{
    CommandLine::iterator it;
    for (it = command.begin(); it != command.end(); it++)
        if ((*it) == field_name)
            return *(it + 1);
    if (it == command.end())
        throw BadRequest();
}

bool UserInterface::has_arguement(string field_name)
{
    for (auto it = command.begin(); it != command.end(); it++)
        if ((*it) == field_name)
            return true;
    return false;
}

void UserInterface::parse_post()
{
    if (command[COMMAND_INDEX] == SIGNUP_COMMAND)
        handle_signup();
    else if (command[COMMAND_INDEX] == LOGIN_COMMAND)
        handle_login();
    else if (command[COMMAND_INDEX] == LOGOUT_COMMAND)
        handle_logout();
    else if (command[COMMAND_INDEX] == WALLET_COMMAND)
        handle_post_wallet();
    else if (command[COMMAND_INDEX] == RESERVE_COMMAND)
        handle_post_reserves();
    else if (command[COMMAND_INDEX] == COMMENT_COMMAND)
        handle_post_comments();
    else if (command[COMMAND_INDEX] == RATING_COMMAND)
        handle_post_ratings();
    else if (command[COMMAND_INDEX] == FILTER_COMMAND)
        handle_post_filters();
    else
        throw NotFound();
}

void UserInterface::parse_get()
{
    if (command[COMMAND_INDEX] == WALLET_COMMAND)
        handle_get_wallet();
    else if (command[COMMAND_INDEX] == HOTEL_COMMAND)
        handle_get_hotels();
    else if (command[COMMAND_INDEX] == RESERVE_COMMAND)
        handle_get_reserves();
    else if (command[COMMAND_INDEX] == COMMENT_COMMAND)
        handle_get_comments();
    else if (command[COMMAND_INDEX] == RATING_COMMAND)
        handle_get_ratings();
    else 
        throw NotFound();
}

void UserInterface::parse_delete()
{
    if (command[COMMAND_INDEX] == RESERVE_COMMAND)
        handle_delete_reserves();
    else if (command[COMMAND_INDEX] == FILTER_COMMAND)
        handle_delete_filters();
    else
        throw NotFound();
}

void UserInterface::handle_delete_filters()
{
    utrip->delete_filters(logged_in_user);
}

void UserInterface::handle_room_filter()
{
    string room_type = get_arguement(ROOM_TYPE);
    int quantity = stoi(get_arguement(QUANTITY));
    int check_in = stoi(get_arguement(CHECK_IN));
    int check_out = stoi(get_arguement(CHECK_OUT));
    utrip->add_room_filter(logged_in_user, room_type, quantity, check_in, check_out);
}

void UserInterface::handle_star_filter()
{
    double min_star = stod(get_arguement(MIN_STAR));
    double max_star = stod(get_arguement(MAX_STAR));
    utrip->add_star_filter(logged_in_user, min_star, max_star);
}

void UserInterface::handle_price_filter()
{
    double min_price = stod(get_arguement(MIN_PRICE));
    double max_price = stod(get_arguement(MAX_PRICE));
    utrip->add_price_filter(logged_in_user, min_price, max_price);
}

void UserInterface::handle_city_filter()
{
    string city = get_arguement(CITY);
    utrip->add_city_filter(logged_in_user, city);
}

void UserInterface::handle_post_filters()
{
    check_permission();
    if (has_arguement(CITY))
        handle_city_filter();
    else if (has_arguement(MIN_PRICE) && has_arguement(MAX_PRICE))
        handle_price_filter();
    else if (has_arguement(MIN_STAR) && has_arguement(MAX_STAR))
        handle_star_filter();
    else if (has_arguement(ROOM_TYPE) && has_arguement(QUANTITY) && has_arguement(CHECK_IN) && has_arguement(CHECK_OUT))
        handle_room_filter();
}

void UserInterface::handle_get_ratings()
{
    check_permission();
    check_minimum_words(GET_RATINGS_COMMAND_MINIMUM_WORDS);
    utrip->show_average_ratings(get_arguement(HOTEL));
}

void UserInterface::handle_post_ratings()
{
    check_permission();
    check_minimum_words(GET_RATINGS_COMMAND_MINIMUM_WORDS);
    string hotel_id = get_arguement(HOTEL);
    double location = stod(get_arguement(LOCATION));
    double cleanliness = stod(get_arguement(CLEANLINESS));
    double staff = stod(get_arguement(STAFF));
    double facilities = stod(get_arguement(FACILITIES));
    double value_for_money = stod(get_arguement(VALUE_FOR_MONEY));
    double overall = stod(get_arguement(OVERALL));
    utrip->add_rating(logged_in_user ,hotel_id, location, cleanliness, staff, facilities, value_for_money, overall);
}

void UserInterface::handle_get_comments()
{
    check_permission();
    check_minimum_words(GET_COMMENT_COMMAND_MINIMUM_WORDS);
    utrip->show_comments(get_arguement(HOTEL));
}

void UserInterface::handle_post_comments()
{
    check_permission();
    check_minimum_words(POST_COMMENT_COMMAND_MINIMUM_WORDS);
    string hotel_id = get_arguement(HOTEL);
    string comment = get_arguement(COMMENT);
    utrip->add_comment(logged_in_user ,hotel_id, comment);
}

void UserInterface::handle_delete_reserves()
{
    check_permission();
    int id = stoi(get_arguement(ID));
    utrip->delete_reservation(logged_in_user, id);
}

void UserInterface::handle_get_reserves()
{
    check_permission();
    utrip->show_reservations(logged_in_user);
}

void UserInterface::handle_post_reserves()
{
    check_permission();
    check_minimum_words(POST_RESERVES_MINIMUM_WORDS);
    string id = get_arguement(HOTEL);
    string room_type = get_arguement(ROOM_TYPE);
    int quantity = stoi(get_arguement(QUANTITY));
    int check_in = stoi(get_arguement(CHECK_IN));
    int check_out = stoi(get_arguement(CHECK_OUT));
    utrip->post_reservation(logged_in_user, id, room_type, quantity, check_in, check_out);
}

void UserInterface::handle_get_hotels()
{
    check_permission();
    if (command.size() == COMMAND_WITHOUT_ARGUMENT_SIZE)
        utrip->show_hotels(logged_in_user);
    else
        utrip->show_hotel(get_arguement(ID));
}

void UserInterface::handle_get_wallet()
{
    check_permission();
    check_minimum_words(WALLET_COMMAND_MINIMUN_WORDS);
    int count = stod(get_arguement(COUNT));
    utrip->show_transactions(logged_in_user, count);
}

void UserInterface::handle_post_wallet()
{
    check_permission();
    check_minimum_words(WALLET_COMMAND_MINIMUN_WORDS);
    double amount = stod(get_arguement(AMOUNT));
    check_amount(amount);
    utrip->add_to_wallet(logged_in_user, amount);
}

void UserInterface::handle_logout()
{
    check_permission();
    utrip->logout(logged_in_user);
    logged_in_user = LOGGED_OUT;
}

void UserInterface::handle_login()
{
    check_login_permission();
    check_minimum_words(LOGIN_COMMAND_MINIMUM_WORDS);
    string email = get_arguement(EMAIL);
    string password = get_arguement(PASSWORD);
    logged_in_user = utrip->login(email, password);
}

void UserInterface::handle_signup()
{   
    check_login_permission();
    check_minimum_words(SIGNUP_COMMAND_MINIMUM_WORDS);
    string username = get_arguement(USERNAME);
    string email = get_arguement(EMAIL);
    string password = get_arguement(PASSWORD);
    logged_in_user = utrip->signup(username, email, password);
}

void UserInterface::parse_command()
{   
    check_question_mark();
    check_minimum_words(MINIMUM_COMMAND_WORDS);
    if (command[COMMAND_TYPE_INDEX] == POST_REQUEST)
        parse_post();
    else if (command[COMMAND_TYPE_INDEX] == GET_REQUEST)
        parse_get();
    else if (command[COMMAND_TYPE_INDEX] == DELETE_REQUEST)
        parse_delete();
    else 
        throw BadRequest();
}

void UserInterface::check_amount(double amount)
{
    if (amount <= 0)
        throw BadRequest();
}

void UserInterface::check_permission()
{
    if (logged_in_user == LOGGED_OUT)
        throw PermissionDenied();
}

void UserInterface::check_login_permission()
{
    if (logged_in_user != LOGGED_OUT)
        throw BadRequest();
}

void UserInterface::check_question_mark()
{
    if (command.size() > COMMAND_WITHOUT_ARGUMENT_SIZE)
        if (command[QUESTION_MARK_INDEX] != QUESTION_MARK)
            throw BadRequest();
}

void UserInterface::check_minimum_words(int minimum_words)
{
    if (command.size() < minimum_words)
        throw BadRequest();
}

void UserInterface::run_program()
{  
    string line;
    while(getline(cin,line))
    {  
        try
        {
            command = parse_string_to_vector(line, COMMAND_LINE_DELIMITER);
            parse_command();
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << '\n';
        }
    }
}
