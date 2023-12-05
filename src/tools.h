//
// Created by Ethan Jones on 05/12/2023.
//

#include <string>

#ifndef ADVENT_OF_CODE_2023_TOOLS_H
#define ADVENT_OF_CODE_2023_TOOLS_H


class tools {
public:
    static bool isAllWhiteSpace(const std::string &str);
    static std::string trimWhitespace(const std::string &str);
    static std::vector<std::string> splitStringBySeparator(const std::string& inputString, char separator);
};


#endif //ADVENT_OF_CODE_2023_TOOLS_H
