#ifndef SERVER_INTERFACE_HPP
#define SERVER_INTERFACE_HPP

#include "../server/server.hpp"

class Utrip;

class ServerInterface {
    public:
    ServerInterface(Utrip* _utrip);
    void run_program();

    private:
    Utrip* utrip;
    void make_get_requests(Server& server);
    void make_post_requests(Server& server);
};

#endif