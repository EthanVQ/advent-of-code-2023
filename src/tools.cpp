//
// Created by Ethan Jones on 05/12/2023.
//

#include "tools.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string tools::trimWhitespace(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");

    if (first == std::string::npos)  // string is all whitespace
        return "";

    return str.substr(first, last - first + 1);
}

bool tools::isAllWhiteSpace(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)  // string is all whitespace
        return true;
    else
    {
        return false;
    }
}

vector<std::string> tools::splitStringBySeparator(const std::string& inputString, char separator)
{
    std::istringstream ss(inputString);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, separator)) {
        tokens.push_back(token);
    }

    return tokens;
}