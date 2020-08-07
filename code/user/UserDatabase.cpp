#include "UserDatabase.hpp"
#include "User.hpp"
#include "../Exception.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<User*> _users;

UserDatabase::~UserDatabase()
{
    for (auto it = users.begin(); it != users.end(); it++)
    {
        delete *it;
        *it = nullptr;
    }
}

User* UserDatabase::login(string email, size_t password_hash)
{
    for (auto it = users.begin(); it != users.end(); it++)
        if ((*it)->get_email() == email && (*it)->is_correct_password(password_hash))
            return *it;
    throw BadRequest();
}

User* UserDatabase::get_user_by_username(std::string username)
{
    for (auto it = users.begin(); it != users.end(); it++)
        if ((*it)->get_username() == username)
            return *it;
}

User* UserDatabase::signup(string username, string email, string password)
{
    check_duplicate_info(username, email);
    User* new_user = new User(username, email, password);
    users.push_back(new_user);
    return new_user;
}

void UserDatabase::check_duplicate_info(string username, string email)
{
    for (auto it = users.begin(); it != users.end(); it++)
        if ((*it)->get_username() == username || (*it)->get_email() == email)
            throw BadRequest();
}