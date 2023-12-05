//
// Created by Ethan Jones on 05/12/2023.
//

#include <string>

#ifndef ADVENT_OF_CODE_2023_DAY5_H
#define ADVENT_OF_CODE_2023_DAY5_H

class day5 {
public:
    static int part1();
    static int part2();

private:
    static bool isAllWhiteSpace(const std::string &str);
    static std::string trimWhitespace(const std::string &str);
    static std::vector<long> splitStringByWhitespace(const std::string& inputString);
};


#endif //ADVENT_OF_CODE_2023_DAY5_H
