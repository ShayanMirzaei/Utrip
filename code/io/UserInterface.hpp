#ifndef USER_INTERFACE
#define USER_INTERFACE

#include <string>
#include <vector>
#include <map>

class Utrip;
typedef std::vector<std::string> CommandLine;
typedef void *CommandFunction(void);
class User;

class UserInterface {
    public:
    UserInterface(Utrip* _utrip);
    ~UserInterface();
    void run_program();

    private:
    Utrip* utrip;
    CommandLine command;
    User* logged_in_user;
    std::string get_arguement(std::string field_name);
    bool has_arguement(std::string field_name);
    void parse_command();
    void parse_post();
    void parse_get();
    void parse_delete();
    void check_question_mark();
    void check_minimum_words(int minimum_words);
    void check_permission();
    void check_login_permission();
    void check_amount(double amount);
    void handle_signup();
    void handle_login();
    void handle_logout();
    void handle_post_wallet();
    void handle_get_wallet();
    void handle_get_hotels();
    void handle_post_reserves();
    void handle_get_reserves();
    void handle_delete_reserves();
    void handle_post_comments();
    void handle_get_comments();
    void handle_post_ratings();
    void handle_get_ratings();
    void handle_post_filters();
    void handle_delete_filters();
    void handle_city_filter();
    void handle_price_filter();
    void handle_room_filter();
    void handle_star_filter();
    void handle_default_price_filter();
    void handle_sort();
    void handle_post_manual_weights();
    void handle_get_manual_weights();
    void handle_get_estimated_weights();
};

#endif