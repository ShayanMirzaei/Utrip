#include "Utrip.hpp"
#include "io/UserInterface.hpp"

#define FILE_DIR 1

using namespace std;

int main(int argc, char const *argv[])
{
    Utrip utrip;
    utrip.read_hotel_info_from_csv(argv[FILE_DIR]);
    UserInterface ui(&utrip);
    ui.run_program();
    return 0;
}
