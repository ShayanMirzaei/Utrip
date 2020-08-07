#ifndef WALLET_HPP
#define WALLET_HPP

#include <vector>

typedef std::vector<double> _transactions;

class Wallet {
    public:
    Wallet();
    void add_credit(double amount);
    _transactions get_transactions() { return transactions; }
    bool has_credit(double amount);
    void decrease_credit(double amount);
    double get_credit() { return credit; }

    private:
    double credit;
    _transactions transactions;
};

#endif