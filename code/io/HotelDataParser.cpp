#include "HotelDataParser.hpp"
#include "../hotel/HotelDatabase.hpp"
#include "../utilities.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "../hotel/Hotel.hpp"

#define CSV_DELIMITER ','

using namespace std;

void HotelDataParser::read_data()
{
    ifstream file(csv_file_dir);
    string line = dump_first_line(file);
    while (getline(file, line))
        database->add_hotel(parse_string_to_vector(line, CSV_DELIMITER));
    database->sort_by_unique_id();
}

string HotelDataParser::dump_first_line(ifstream& file)
{
    string dump;
    getline(file, dump);
    return dump;
}

