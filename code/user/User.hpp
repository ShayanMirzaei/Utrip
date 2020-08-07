#ifndef USER_HPP
#define USER_HPP

#include <functional>
#include <string>
#include <vector>
#include <map>

class Wallet;
class Filter;
typedef std::vector<double> _transactions;
class Reservation;
typedef std::vector<Reservation*> _reservations;
typedef std::vector<Filter* > _filters;
class Sort;
class Weight;
class Rating;
class Hotel;
typedef std::map<Hotel*, Rating*> hotel_ratings;


class User {
    public:
    User(std::string _username, std::string email, std::string password);
    ~User();
    std::string get_username() { return username; }
    std::string get_email() { return email; }
    bool is_correct_password(size_t _hash);
    Wallet* get_wallet() { return wallet; }
    void check_credit(double amount);
    _transactions get_transactions();
    void add_reservation(Reservation* reservation);
    _reservations get_reservations() { return reservations; }
    Reservation* cancel_reservation(int id);
    Reservation* remove_reservation(int id);
    void add_filter(Filter* filter);
    void delete_filters();
    _filters get_filters() { return filters; }
    void activate_default_price_filter() { active_default_filter_price = true; }
    void deactivate_default_price_filter() { active_default_filter_price = false; }
    bool can_apply_default_price_filter();
    void set_sort(Sort* _sort);
    Sort* get_sort() { return sort; }
    void set_manual_weights(Weight* _weight);
    void deactivate_manual_weights();
    void handle_personal_rating();
    void add_rating(Hotel* hotel, Rating* rating);
    Weight* get_manual_weights() { return manual_weight; }
    Weight* get_estimated_weights();
    std::string get_manual_weight_mode();
    
    private:
    std::string username;
    std::string email;
    size_t password_hash;
    Wallet* wallet;
    _reservations reservations;
    _filters filters;
    hotel_ratings ratings;
    int reservation_id_counter;
    int get_next_reservation_id();
    std::vector<std::string> rated_hotels;
    bool active_default_filter_price;
    Sort* sort;
    Weight* manual_weight;
    Weight* estimated_weight;
    bool active_manual_weight;
    bool personal_weight_should_change;
    std::vector<Rating*> ratings_to_vector();
};

#endif