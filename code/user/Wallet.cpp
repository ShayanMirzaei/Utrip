#include "Wallet.hpp"
#include <vector>

#define STARTING_CREDIT 0

using namespace std;

Wallet::Wallet()
{
    credit = STARTING_CREDIT;
    transactions.push_back(credit);
}

void Wallet::add_credit(double amount)
{
    credit += amount;
    transactions.push_back(credit);
}

void Wallet::decrease_credit(double amount)
{
    credit -= amount;
    transactions.push_back(credit);
}

bool Wallet::has_credit(double amount)
{
    if (amount <= credit)
        return true;
    return false;
}