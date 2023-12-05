//
// Created by Ethan Jones on 05/12/2023.
//

#include "day5.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


int day5::part1() {

    // read file

    std::vector<vector<vector<long>>> mappings;

    std::vector<long> seeds;

    std::ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day5/puzzle.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    std::string line;
    vector<vector<long>> mapping;

    while (std::getline(inputFile, line)) {
        if(line.find("seeds:") != std::string::npos)
        {
            // parse seeds
            std::string seedString = line.substr(line.find(":") + 2);
            seedString = trimWhitespace(seedString);
            seeds = splitStringByWhitespace(seedString);
        }
        else if (line.find(":") != std::string::npos)
        {
            mapping.clear();
        }
        else if (isAllWhiteSpace(line))
        {
            if(mapping.size()!=0)
            {
                mappings.push_back(mapping);
            }
            continue;
        }
        else
        {
            string trimmedLine = trimWhitespace(line);
            mapping.push_back(splitStringByWhitespace(trimmedLine));
        }
    }

    mappings.push_back(mapping);     // add last one

    inputFile.close();

    // find locations

    std::vector<long> locations;

    for(long seed : seeds) {
        long currentVal = seed;
        for (vector mapping : mappings) {
            for (vector set : mapping) {
                if (currentVal < set[1] + set[2] && currentVal >= set[1]) {
                    long diff = currentVal - set[1];
                    currentVal = set[0] + diff;
                    break;
                }
            }
        }
        locations.push_back(currentVal);
    }

    long answer = *std::min_element(locations.begin(), locations.end());
    std::cout << "Day 5 Part 1: " << answer << std::endl;

    return 0;
}

int day5::part2() {

    // read file

    std::vector<vector<vector<long>>> mappings;

    std::vector<long> seeds;

    std::ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day5/puzzle.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    std::string line;
    vector<vector<long>> mapping;

    while (std::getline(inputFile, line)) {
        if(line.find("seeds:") != std::string::npos)
        {
            // parse seeds
            std::string seedString = line.substr(line.find(":") + 2);
            seedString = trimWhitespace(seedString);
            seeds = splitStringByWhitespace(seedString);
        }
        else if (line.find(":") != std::string::npos)
        {
            mapping.clear();
        }
        else if (isAllWhiteSpace(line))
        {
            if(mapping.size()!=0)
            {
                mappings.push_back(mapping);
            }
            continue;
        }
        else
        {
            string trimmedLine = trimWhitespace(line);
            mapping.push_back(splitStringByWhitespace(trimmedLine));
        }
    }

    mappings.push_back(mapping);     // add last one

    inputFile.close();

    // process seed ranges

    vector<vector<long>> seedRanges;

    for(int i=0; i<seeds.size(); i+=2)
    {
        vector<long> range;
        for (int j = seeds[i]; j < seeds[i] + seeds[i+1]; ++j) {
           range.push_back(j);
        }
        seedRanges.push_back(range);
    }

    // find locations

    std::vector<long> locations;

    for(vector<long> range : seedRanges) {
        std::vector<long> locationsFoRange;
        for (long seed : range) {
            long currentVal = seed;
            for (vector mapping: mappings) {
                for (vector set: mapping) {
                    if (currentVal < set[1] + set[2] && currentVal >= set[1]) {
                        long diff = currentVal - set[1];
                        currentVal = set[0] + diff;
                        break;
                    }
                }
            }
            locationsFoRange.push_back(currentVal);
        }
        locations.push_back(*std::min_element(locationsFoRange.begin(), locationsFoRange.end()));
    }

    long answer = *std::min_element(locations.begin(), locations.end());
    std::cout << "Day 5 Part 2: " << answer << std::endl;

    return 0;
}

string day5::trimWhitespace(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");

    if (first == std::string::npos)  // string is all whitespace
        return "";

    return str.substr(first, last - first + 1);
}

bool day5::isAllWhiteSpace(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)  // string is all whitespace
        return true;
    else
    {
        return false;
    }
}

vector<long> day5::splitStringByWhitespace(const std::string& inputString)
{
    std::istringstream iss(inputString);
    std::vector<long> numbers;

    while (iss >> std::ws) {
        std::string number;
        iss >> number;

        numbers.push_back(std::stol(number));
    }

    return numbers;
}