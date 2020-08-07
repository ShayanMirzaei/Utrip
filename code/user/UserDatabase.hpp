#ifndef USER_DATABASE
#define USER_DATABASE

#include <vector>
#include <string>

class User;
typedef std::vector<User*> _users;

class UserDatabase {
    public:
    ~UserDatabase();
    User* signup(std::string username, std::string email, std::string password);
    User* login(std::string email, size_t password_hash);
    User* get_user_by_username(std::string username);

    private:
    _users users;  
    void check_duplicate_info(std::string username, std::string email);  
};

#endif

