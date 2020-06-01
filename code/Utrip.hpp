#ifndef UTRIP_HPP
#define UTRIP_HPP

#include <string>

class HotelDatabase;
class UserDatabase;
class User;
class Output;

class Utrip {
    public:
    Utrip();
    ~Utrip();
    void read_hotel_info_from_csv(std::string hotel_file_dir);
    User* signup(std::string username, std::string email, std::string password);
    User* login(std::string email, std::string password);
    void logout(User* user);
    void add_to_wallet(User* user, double amount);
    void show_transactions(User* user, int count);
    void show_hotel(std::string id);
    void show_hotels(User* user);
    void post_reservation(User* user, std::string hotel_id, std::string room_type, int quantity, int check_in, int check_out);
    void show_reservations(User* user);
    void delete_reservation(User* user, int id);
    void add_comment(User* user, std::string hotel_id, std::string comment);
    void add_rating(User* user, std::string hotel_id, double location, double cleanliness, double staff, double facilities, double value_for_money, double overall_rating);
    void show_comments(std::string hotel_id);
    void show_average_ratings(std::string hotel_id);
    void add_city_filter(User* user, std::string city);
    void add_price_filter(User* user, double min_price, double max_price);
    void add_star_filter(User* user, int min_star, int max_star);
    void add_room_filter(User* user, std::string room_type, int quantity, int check_in, int check_out);
    void delete_filters(User* user);

    private:
    HotelDatabase* hotel_database;
    UserDatabase* user_database;
    Output* output;
    void check_empty(int size);
    void check_prices(double min, double max);
    void check_stars(int min, int max);
};

#endif