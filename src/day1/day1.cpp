//
// Created by Ethan Jones on 24/11/2023.
//

#include"day1.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int day1::part1()
{
    // read files

    std::ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day1/puzzle.txt");

    if(!inputFile.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    std::vector<std::string> listOfStrings;
    std::string line;

    while (std::getline(inputFile, line))
    {
        listOfStrings.push_back(line);
    }

    inputFile.close();

    // get calibration values

    std::list<int> calibrations = {};

    for(string j : listOfStrings)
    {
        std::list<char> digits = {};

        for(char i : j)
        {
            if (isdigit(i))
            {
                digits.push_back(i);
            }
        }

        std:string calValue = std::string(1, digits.front()) + std::string(1, digits.back());

        calibrations.push_back(std::stoi(calValue));
    }

    // total and print calibration values

    int total = 0;
    for(const auto& calValue : calibrations)
    {
        total += calValue;
    }

    std::cout << "Day 1 Part 1: " << total << std::endl;
    return 0;
}

int day1::part2()
{
    // read files

    std::ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day1/puzzle.txt");

    if(!inputFile.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    std::vector<std::string> listOfStrings;
    std::string line;

    while (std::getline(inputFile, line))
    {
        listOfStrings.push_back(line);
    }

    inputFile.close();

    // get calibration values

    std::list<int> calibrations = {};

    std::vector<std::string> digitWords = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> digitChars = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for(string stringLine : listOfStrings)
    {
        std::list<string> digits = {};

        for(std::size_t i = 0; i < stringLine.length(); ++i)
        {
            char currentLetter = stringLine[i];
            if (isdigit(currentLetter))
            {
                digits.push_back(std::string(1, currentLetter));
            }
            else
            {
                for(std::size_t k = 0; k < digitWords.size() ; ++k)
                {
                    string digitWord = digitWords[k];

                    if (i + digitWord.length() - 1 >= stringLine.length())
                    {
                        continue;
                    }

                    bool full_match = true;
                    int digit_iterator = 0;

                    for(std::size_t j = i; j < i + digitWord.length(); ++j)
                    {
                        if(stringLine[j] != digitWord[digit_iterator])
                        {
                            full_match = false;
                            break;
                        }

                        digit_iterator++;
                    }

                    if(full_match)
                    {
                        digits.push_back(digitChars[k]);
                        break;
                    }
                }
            }
        }

        std:string calValue = digits.front() + digits.back();

        calibrations.push_back(std::stoi(calValue));
    }

    // total and print calibration values

    int total = 0;
    for(const auto& calValue : calibrations)
    {
        total += calValue;
    }

    std::cout << "Day 1 Part 2: " << total << std::endl;
    return 0;
}