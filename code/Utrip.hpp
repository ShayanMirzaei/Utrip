#ifndef UTRIP_HPP
#define UTRIP_HPP

#include <string>
#include <vector>

class HotelDatabase;
class UserDatabase;
class User;
class Output;
class Hotel;
typedef std::vector<Hotel*> _hotels;

class Utrip {
    public:
    Utrip();
    ~Utrip();
    void read_hotel_info_from_csv(std::string hotel_file_dir, std::string rating_file_dir);
    User* signup(std::string username, std::string email, std::string password);
    User* login(std::string email, std::string password);
    void logout(User* user);
    void add_to_wallet(User* user, double amount);
    void show_transactions(User* user, int count);
    void show_hotel(std::string id);
    _hotels show_hotels(User* user);
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
    void activate_default_price_filter(User* user);
    void deactivate_default_price_filter(User* user);
    void add_sort_to_user(User* user, std::string property, bool order);
    void deactivate_manual_weights(User* user);
    void activate_manual_weights(User* user, double location_w, double cleanliness_w, double staff_w, double facilities_w, double value_for_money_w);
    void show_manual_weights(User* user);
    void show_estimated_weights(User* user);
    User* get_user_by_username(std::string username);
    Hotel*  get_hotel_by_id(std::string id);

    private:
    HotelDatabase* hotel_database;
    UserDatabase* user_database;
    Output* output;
    void check_empty(int size);
    void check_prices(double min, double max);
    void check_stars(int min, int max);
    void check_weights(std::vector<double> weights);
    void handle_default_price_filter(User* user);
    void handle_user_sort(User* user, _hotels& hotels);
};

#endif