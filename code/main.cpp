#include "Utrip.hpp"
#include "io/ServerInterface.hpp"
#include "server/server.hpp"
#include "server/route.hpp"
#include <iostream>

#define HOTEL_FILE_DIR 1
#define RATING_FILE_DIR 2

using namespace std;

int main(int argc, char const *argv[])
{
    Utrip utrip;
    utrip.read_hotel_info_from_csv(argv[HOTEL_FILE_DIR], argv[RATING_FILE_DIR]);
    ServerInterface interface(&utrip);
    interface.run_program();
    return 0;
}
