//
// Created by Ethan Jones on 05/12/2023.
//

#include "day3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "../tools.h"
#include <map>
#include <list>

using namespace std;

int day3::part1() {

    // read and parse file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day3/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    std::string line;

    vector<vector<char>> schematic;

    while (getline(inputFile, line)) {
        vector<char> schematicLine;
        for (int i = 0; i < line.length(); ++i) {
            schematicLine.push_back(line[i]);
        }
        schematic.push_back(schematicLine);
    }

    // solve

    vector<vector<int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

    long answer = 0;

    vector<vector<int>> coordinatesOfNumbersUsed;

    for (int row = 0 ; row < schematic.size() ; row++)
    {
        for (int col = 0 ; col < schematic[0].size() ; col++)
        {
            if(!isdigit(schematic[row][col]) && schematic[row][col] != '.')
            {
                // search around special character
                for(vector<int> direction : directions)
                {
                    tuple<long,vector<vector<int>>> result = discoverNumber(row + direction[0], col + direction[1], schematic, coordinatesOfNumbersUsed, answer);
                    answer = get<0>(result);
                    coordinatesOfNumbersUsed = get<1>(result);
                }
            }
        }
    }

    cout << "Day 3 Part 1: " << answer << endl;

    return 0;
}

tuple<long,vector<vector<int>>> day3::discoverNumber(int rowStart, int colStart, vector<vector<char>> schematic, vector<vector<int>> coordinatesOfNumbersUsed, long answer)
{
    list<char> digits;

    if(rowStart >= schematic.size() || colStart >= schematic[0].size() || rowStart < 0 || colStart < 0)
    {
        return { answer, coordinatesOfNumbersUsed };
    }

    if(schematic[rowStart][colStart] == '.')
    {
        return { answer, coordinatesOfNumbersUsed };
    }

    digits.push_back(schematic[rowStart][colStart]);

    vector<int> startingCoordinate { rowStart, colStart};

    // look left
    for(int col = colStart-1 ; col >= 0 ; col--)
    {
        if(isdigit(schematic[rowStart][col]))
        {
            digits.push_front(schematic[rowStart][col]);
            startingCoordinate = vector<int> { rowStart, col };
        }
        else
        {
            break;
        }
    }

    // look right
    for(int col = colStart+1 ; col < schematic[0].size() ; col++)
    {
        if(isdigit(schematic[rowStart][col]))
        {
            digits.push_back(schematic[rowStart][col]);
        }
        else
        {
            break;
        }
    }

    // check if starting coordinate has already been used

    for(vector<int> coordinate : coordinatesOfNumbersUsed)
    {
        if(coordinate[0] == startingCoordinate[0] && coordinate[1] == startingCoordinate[1])
        {
            return { answer, coordinatesOfNumbersUsed};
        }
    }

    // compile number and add existing coord

    string partNumber(digits.begin(), digits.end());

    answer += stol(partNumber);

    coordinatesOfNumbersUsed.push_back(startingCoordinate);

    return { answer, coordinatesOfNumbersUsed };
}

int day3::part2() {

    // read and parse file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day3/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    std::string line;

    vector<vector<char>> schematic;

    while (getline(inputFile, line)) {
        vector<char> schematicLine;
        for (int i = 0; i < line.length(); ++i) {
            schematicLine.push_back(line[i]);
        }
        schematic.push_back(schematicLine);
    }

    // solve

    vector<vector<int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

    long answer = 0;

    for (int row = 0 ; row < schematic.size() ; row++)
    {
        for (int col = 0 ; col < schematic[0].size() ; col++)
        {
            if(schematic[row][col] == '*')
            {
                // search around special character
                vector<vector<int>> coordinatesOfNumbersUsed;

                vector<long> gearParts;

                for(vector<int> direction : directions)
                {
                    tuple<long,vector<vector<int>>> result = discoverNumberTwo(row + direction[0], col + direction[1], schematic, coordinatesOfNumbersUsed);
                    if(get<0>(result) >= 0 )
                    {
                        gearParts.push_back(get<0>(result));
                    }
                    coordinatesOfNumbersUsed =  get<1>(result);
                }

                if(gearParts.size()==2)
                {
                    answer += gearParts[0] * gearParts[1];
                }
            }
        }
    }

    cout << "Day 3 Part 1: " << answer << endl;

    return 0;
}

tuple<long,vector<vector<int>>> day3::discoverNumberTwo(int rowStart, int colStart, vector<vector<char>> schematic, vector<vector<int>> coordinatesOfNumbersUsed)
{
    list<char> digits;

    if(rowStart >= schematic.size() || colStart >= schematic[0].size() || rowStart < 0 || colStart < 0)
    {
        return { -1, coordinatesOfNumbersUsed };
    }

    if(schematic[rowStart][colStart] == '.')
    {
        return { -1, coordinatesOfNumbersUsed };
    }

    digits.push_back(schematic[rowStart][colStart]);

    vector<int> startingCoordinate { rowStart, colStart};

    // look left
    for(int col = colStart-1 ; col >= 0 ; col--)
    {
        if(isdigit(schematic[rowStart][col]))
        {
            digits.push_front(schematic[rowStart][col]);
            startingCoordinate = vector<int> { rowStart, col };
        }
        else
        {
            break;
        }
    }

    // look right
    for(int col = colStart+1 ; col < schematic[0].size() ; col++)
    {
        if(isdigit(schematic[rowStart][col]))
        {
            digits.push_back(schematic[rowStart][col]);
        }
        else
        {
            break;
        }
    }

    // check if starting coordinate has already been used

    for(vector<int> coordinate : coordinatesOfNumbersUsed)
    {
        if(coordinate[0] == startingCoordinate[0] && coordinate[1] == startingCoordinate[1])
        {
            return { -1, coordinatesOfNumbersUsed};
        }
    }

    // compile number and add existing coord

    string partNumber(digits.begin(), digits.end());

    coordinatesOfNumbersUsed.push_back(startingCoordinate);

    return { stol(partNumber), coordinatesOfNumbersUsed };
}