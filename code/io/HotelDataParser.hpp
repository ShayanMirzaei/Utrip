#ifndef HOTEL_DATA_PARSER_HPP
#define HOTEL_DATA_PARSER_HPP

#include <string>
#include <vector>

class HotelDatabase;
class Hotel;

class HotelDataParser {
    public:
    HotelDataParser(HotelDatabase* _database, std::string hotel_file_dir, std::string rating_file_dir): database(_database), hotel_csv_file_dir(hotel_file_dir), rating_csv_file_dir(rating_file_dir) {};
    void read_data();
    std::string dump_first_line(std::ifstream& file);

    private:
    HotelDatabase* database;
    std::string hotel_csv_file_dir;
    std::string rating_csv_file_dir;
    void read_hotel_data();
    void read_ratings();
};

#endif