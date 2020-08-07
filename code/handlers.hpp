#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include "server/route.hpp"
#include "server/server.hpp"
#include "utils/request.hpp"
#include "utils/response.hpp"

class Utrip;

class Login : public RequestHandler {
    public:
    Login(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class LoginHandler : public RequestHandler {
    public:
    LoginHandler(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class ShowHotels : public RequestHandler {
    public:
    ShowHotels(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class SignUp : public RequestHandler {
    public:
    SignUp(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class SignUpHandler : public RequestHandler {
    public:
    SignUpHandler(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};


class ShowHotelProperties : public RequestHandler {
    public:
    ShowHotelProperties(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class FilterByStar : public RequestHandler {
    public:
    FilterByStar(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class Logout : public RequestHandler {
    public:
    Logout(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class ShowWallet : public RequestHandler {
    public:
    ShowWallet(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

class UpdateWallet : public RequestHandler {
    public:
    UpdateWallet(Utrip* _utrip) : utrip(_utrip) {};
    Response* callback(Request* req);

    private:
    Utrip* utrip;
};

#endif