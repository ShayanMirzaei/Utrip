#ifndef USER_HPP
#define USER_HPP

#include <functional>
#include <string>
#include <vector>

class Wallet;
class Filter;
typedef std::vector<double> _transactions;
class Reservation;
typedef std::vector<Reservation*> _reservations;
typedef std::vector<Filter* > _filters;

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
    
    private:
    std::string username;
    std::string email;
    size_t password_hash;
    Wallet* wallet;
    _reservations reservations;
    _filters filters;
    int reservation_id_counter;
    int get_next_reservation_id();
    std::vector<std::string> rated_hotels;
};

#endif