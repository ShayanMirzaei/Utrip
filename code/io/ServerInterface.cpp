#include "ServerInterface.hpp"
#include "../server/server.hpp"
#include "../server/route.hpp"
#include "../Utrip.hpp"
#include "../handlers.hpp"
#include <iostream>

using namespace std;

ServerInterface::ServerInterface(Utrip* _utrip)
{
    utrip = _utrip;
}

void ServerInterface::make_get_requests(Server& server)
{
    server.get("/", new Login(utrip));
    server.get("/home", new ShowHotels(utrip));
    server.get("/signUp", new SignUp(utrip));
    server.get("/hotelProperties", new ShowHotelProperties(utrip));
    server.get("/logout", new Logout(utrip));
    server.get("/wallet", new ShowWallet(utrip));
}

void ServerInterface::make_post_requests(Server& server)
{
    server.post("/loginHandler", new LoginHandler(utrip));
    server.post("/signUpHandler", new SignUpHandler(utrip));
    server.post("/filterStar", new FilterByStar(utrip));
    server.post("/updateWallet", new UpdateWallet(utrip));
}

void ServerInterface::run_program()
{
    try
    {
        Server server(1111);
        make_get_requests(server);
        make_post_requests(server);
        server.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
