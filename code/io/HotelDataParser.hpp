#ifndef HOTEL_DATA_PARSER_HPP
#define HOTEL_DATA_PARSER_HPP

#include <string>
#include <vector>

class HotelDatabase;
class Hotel;

class HotelDataParser {
    public:
    HotelDataParser(HotelDatabase* _database, std::string _file_dir): database(_database), csv_file_dir(_file_dir) {};
    void read_data();
    std::string dump_first_line(std::ifstream& file);

    private:
    HotelDatabase* database;
    std::string csv_file_dir;
    
};

#endif