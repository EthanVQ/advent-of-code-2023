//
// Created by Ethan Jones on 05/12/2023.
//

#include "day4.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "../tools.h"
#include <map>
#include <list>

using namespace std;

int day4::part1() {

    // read and parse file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day4/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    std::string line;

    vector <vector<char>> schematic;

    while (getline(inputFile, line)) {
    }

    // solve
}

int day4::part2() {

    // read and parse file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day4/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    std::string line;

    vector <vector<char>> schematic;

    while (getline(inputFile, line)) {
    }

    // solve
}