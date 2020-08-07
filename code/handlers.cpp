#include "handlers.hpp"
#include "server/server.hpp"
#include "utils/response.hpp"
#include "utils/request.hpp"
#include <sstream>
#include <string>
#include "Utrip.hpp"
#include "Exception.hpp"
#include <iostream>
#include "user/User.hpp"
#include <vector>
#include "hotel/Hotel.hpp"
#include "hotel/RoomManager.hpp"
#include "user/Wallet.hpp"

using namespace std;

typedef vector<Hotel*> _hotels;

Response* Login::callback(Request* req)
{
    Response* res = new Response;
    res->setHeader("Content-Type", "text/html");

    ostringstream body;
    body
    << "<html>" << endl
    << "<head><title>Login</title></head>" << endl
    << "<body>" << endl
    << "  <p>Welcome to Utrip!</p>" << endl
    << "  <form action='loginHandler' method='POST'" << endl
    << "    <label for='email'>Email:</label><br>" << endl
    << "    <input type='text' id='email' name='email' value='example@ut.ac.ir'><br>" << endl
    << "    <label for='pword'>Password:</label><br>" << endl
    << "    <input type='password' id='pword' name='password' value='******'><br>" << endl
    << "    <input type='submit' value='Submit'>" << endl
    << "  </form>" << endl
    << "  <p>Don't have an account?</p>" << endl
    << "  <a href='/signUp'>Sign Up</a>" << endl
    << "</body>" << endl
    << "</html>" << endl;
    res->setBody(body.str());
    return res;
}

Response* LoginHandler::callback(Request* req)
{
    string email = req->getBodyParam("email");
    string password = req->getBodyParam("password");
    try
    {
        User* user = utrip->login(email, password);
        string sessionId = user->get_username();
        Response* res = Response::redirect("/home");
        res->setSessionId(sessionId);
        return res;
    }
    catch(const BadRequest& e)
    {
        return Response::redirect("/");
    }
}

Response* ShowHotels::callback(Request* req)
{
    Response* res = new Response;
    res->setHeader("Content-Type", "text/html");
    string username = req->getSessionId();
    User* user = utrip->get_user_by_username(username);
    _hotels hotels = utrip->show_hotels(user);
    ostringstream body;
    body
    << "<html>" << endl
    << "<head><title>Home</title></head>" << endl
    << "<body>" << endl
    << "<a href='/logout'>Logout </a><br>" << endl
    << "<a href='/wallet'>Wallet </a><br>" << endl
    << "<p>Filter Hotels by Star Rating: </p>" << endl
    << "  <form action='/filterStar' method='POST'" << endl
    << "    <label for='minimumStar'>Minimum Star:</label><br>" << endl
    << "    <input type='text' id='minimumStar' name='minimumStar' value='1'><br>" << endl
    << "    <label for='maximumStar'>Maximum Star:</label><br>" << endl
    << "    <input type='text' id='maximumStar' name='maximumStar' value='5'><br>" << endl
    << "    <input type='submit' value='Submit'>" << endl
    << "  <h1>Hotels: </h2>" << endl;
    for (auto it = hotels.begin(); it != hotels.end(); it++)
        body
        << "<img src='" << (*it)->get_image_url() << "' alt='Image not Found' style='width:300px;height:300px;'><br>" << endl
        << "<a href='hotelProperties?id=" << (*it)->get_unique_id() << "'>Property Name: " << (*it)->get_properties().name << "</a>" << endl
        << "<p>Star Rating: " << (*it)->get_properties().rating << "</p>" << endl
        << "<p>City: " << (*it)->get_location().city << "</p>" << endl;
    body
    << "</body>" << endl
    << "</html>" << endl;
    res->setBody(body.str());
    res->setSessionId(username);
    return res;
}

Response* ShowWallet::callback(Request* req)
{
    Response* res = new Response;
    res->setHeader("Content-Type", "text/html");
    string username = req->getSessionId();
    User* user = utrip->get_user_by_username(username);
    ostringstream body;
    body
    << "<html>" << endl
    << "<head><title>Wallet</title></head>" << endl
    << "<body>" << endl
    << "<a href='/logout'>Logout </a><br>" << endl
    << "<a href='/home'>Home </a><br>" << endl
    << "<p>Current Credit: " << user->get_wallet()->get_credit() << "</p>" << endl
    << "  <form action='/updateWallet' method='POST'" << endl
    << "    <label for='addCredit'>Add Credit:</label><br>" << endl
    << "    <input type='text' id='addCredit' name='addCredit' value='0'><br>" << endl
    << "    <input type='submit' value='Submit'>" << endl
    << "</body>" << endl
    << "</html>" << endl;
    res->setBody(body.str());
    res->setSessionId(username);
    return res;
}

Response* UpdateWallet::callback(Request* req)
{
    double credit = stod(req->getBodyParam("addCredit"));
    string username = req->getSessionId();
    User* user = utrip->get_user_by_username(username);
    Response* res = Response::redirect("/wallet");
    res->setSessionId(username);
    utrip->add_to_wallet(user, credit);
    return res;
}

Response* FilterByStar::callback(Request* req)
{
    string username = req->getSessionId();
    int minimum_star = stoi(req->getBodyParam("minimumStar"));
    int maximum_star = stoi(req->getBodyParam("maximumStar"));
    try
    {
        User* user = utrip->get_user_by_username(username);
        utrip->add_star_filter(user, minimum_star, maximum_star);
        Response* res = Response::redirect("/home");
        res->setSessionId(username);
        return res;
    }
    catch(const exception& e)
    {
        return Response::redirect("/home");
    }
}

Response* SignUp::callback(Request* req)
{
    Response* res = new Response;
    res->setHeader("Content-Type", "text/html");

    ostringstream body;
    body
    << "<html>" << endl
    << "<head><title>Sign Up</title></head>" << endl
    << "<body>" << endl
    << "  <p>Welcome to Utrip!</p>" << endl
    << "  <form action='signUpHandler' method='POST'" << endl
    << "    <label for='uname'>Username:</label><br>" << endl
    << "    <input type='text' id='uname' name='username' value='example@ut.ac.ir'><br>" << endl
    << "    <label for='email'>Email:</label><br>" << endl
    << "    <input type='text' id='email' name='email' value='example@ut.ac.ir'><br>" << endl
    << "    <label for='pword'>Password:</label><br>" << endl
    << "    <input type='password' id='pword' name='password' value='******'><br>" << endl
    << "    <label for='confirmpword'>Confirm Password:</label><br>" << endl
    << "    <input type='password' id='confirmpword' name='confirmPassword' value='******'><br>" << endl
    << "    <input type='submit' value='Submit'>" << endl
    << "  </form>" << endl
    << "</body>" << endl
    << "</html>" << endl;
    res->setBody(body.str());
    return res;
}

Response* SignUpHandler::callback(Request* req)
{
    string username = req->getBodyParam("username");
    string email = req->getBodyParam("email");
    string password = req->getBodyParam("password");
    string confirm_password = req->getBodyParam("confirmPassword");
    try
    {
        if (password != confirm_password)
            throw BadRequest();
        utrip->signup(username, email, password);
        return Response::redirect("/");
    }
    catch(const BadRequest& e)
    {
        return Response::redirect("/signUp");
    }
}

Response* Logout::callback(Request* req)
{
    Response* res = Response::redirect("/");
    User* user = utrip->get_user_by_username(req->getSessionId());
    utrip->logout(user);
    return res;
}

Response* ShowHotelProperties::callback(Request* req)
{
    Response* res = new Response;
    res->setHeader("Content-Type", "text/html");
    string username = req->getSessionId();
    Hotel* hotel = utrip->get_hotel_by_id(req->getQueryParam("id"));
    ostringstream body;
    body
    << "<html>" << endl
    << "<head><title>Hotel Properties</title></head>" << endl
    << "<body>" << endl
    << "<a href='/logout'>Logout </a><br>" << endl
    << "<a href='/home'>Home</a><br><br>" << endl
    << "<img src='" << hotel->get_image_url() << "' alt='Image not Found' style='width:500px;height:500px;'>" << endl
    << "<p>Property Name: " << hotel->get_properties().name << "</p>" << endl
    << "<p>Overview: " << hotel->get_properties().hotel_overview << "</p>" << endl
    << "<p>Amenities: " << hotel->get_properties().amenities << "</p>" << endl
    << "<p>Star Rating: " << hotel->get_properties().rating << "</p>" << endl
    << "<p>City: " << hotel->get_location().city << "</p>" << endl
    << "            <table border=1>" << endl
    << "                <tr>" << endl
    << "                    <th>&nbsp;</th>" << endl
    << "                    <th>Count</th>" << endl
    << "                    <th>Price</th>" << endl
    << "                </tr>" << endl
    << "                    <tr>" << endl
    << "                        <td>Standard</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_numbers()[standard]<< "</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_prices()[standard] << "</td>" << endl
    << "                    </tr>" << endl
    << "                     <tr>" << endl
    << "                        <td>Deluxe</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_numbers()[deluxe]<< "</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_prices()[deluxe] << "</td>" << endl
    << "                    </tr>" << endl
    << "                    <tr>" << endl
    << "                        <td>Luxury</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_numbers()[luxury]<< "</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_prices()[luxury] << "</td>" << endl
    << "                    </tr>" << endl
    << "                    <tr>" << endl
    << "                        <td>Premium</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_numbers()[premium]<< "</td>" << endl
    << "                        <td>" << hotel->get_room_manager()->get_room_prices()[premium] << "</td>" << endl
    << "                    </tr>" << endl
    << "</body>" << endl
    << "</html>" << endl;
    res->setBody(body.str());
    res->setSessionId(username);
    return res;
}


