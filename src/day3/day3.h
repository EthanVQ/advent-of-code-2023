//
// Created by Ethan Jones on 05/12/2023.
//

#ifndef ADVENT_OF_CODE_2023_DAY3_H
#define ADVENT_OF_CODE_2023_DAY3_H

#include <vector>

using namespace std;

class day3 {
public:
    static int part1();
    static int part2();
private:
    static tuple<long,vector<vector<int>>> discoverNumber(int rowStart, int colStart, vector<vector<char>> schematic, vector<vector<int>> coordinatesOfNumbersUsed, long answer);
    static tuple<long,vector<vector<int>>> discoverNumberTwo(int rowStart, int colStart, vector<vector<char>> schematic, vector<vector<int>> coordinatesOfNumbersUsed);
};


#endif //ADVENT_OF_CODE_2023_DAY3_H
