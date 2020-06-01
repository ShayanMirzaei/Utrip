#include "utilities.hpp"
#include <string>
#include <vector>

using namespace std;

vector<string> parse_string_to_vector(string line, char delimiter)
{
    vector<string> data;
    int delimiter_pos;
    while ((delimiter_pos = line.find(delimiter)) != string::npos)
    {
        data.push_back(line.substr(0, delimiter_pos));
        line = line.substr(delimiter_pos + 1);
    }
    data.push_back(line.substr(delimiter_pos + 1));
    return data;
}

