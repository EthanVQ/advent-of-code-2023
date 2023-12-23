//
// Created by Ethan Jones on 21/12/2023.
//

#include "day21.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "../tools.h"

using namespace std;

void printGarden(vector<vector<char>> garden, vector<vector<int>> coords)
{
    cout << endl;
    for(vector<int> coord : coords)
    {
        garden[coord[0]][coord[1]] = 'O';
    }

    for(vector<char> row : garden)
    {
        for(char ch : row)
        {
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;
}

int day21::part1()
{
    // read file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day21/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    string line;
    vector<vector<char>> garden;
    int row = 0;
    int col;
    vector<int> start;

    while (getline(inputFile, line)) {
        vector<char> item;
        col = 0;
        for (auto it = line.begin(); it != line.end(); ++it) {
            char ch = *it;
            if(ch=='S')
            {
                start = { col, row };
                item.push_back('.');
            }
            else
            {
                item.push_back(ch);
            }
            col++;
        }
        garden.push_back(item);
        row++;
    }

    // solve

    vector<vector<int>> coords = { start };
    int rows = garden.size();
    int columns = garden[0].size();
    int steps = 64;

//    printGarden(garden, coords);

    for(int step = 0 ; step < steps ; step++)
    {
        vector<vector<int>> newCoords;
        for(vector<int> coord : coords)
        {
            if(coord[0]-1 >= 0 && garden[coord[0]-1][coord[1]] == '.')
            {
                // north
                newCoords.push_back({ coord[0]-1, coord[1]});
            }
            if(coord[0]+1 < rows && garden[coord[0]+1][coord[1]] == '.')
            {
                // south
                newCoords.push_back({ coord[0]+1, coord[1]});
            }
            if(coord[1]+1 < columns && garden[coord[0]][coord[1]+1] == '.')
            {
                //east
                newCoords.push_back({ coord[0], coord[1]+1});
            }
            if(coord[1]-1 >= 0 && garden[coord[0]][coord[1]-1] == '.')
            {
                //west
                newCoords.push_back({ coord[0], coord[1]-1});
            }
        }

        // get unique coords

        vector<vector<int>> uniqueNewCoords;
        for(vector<int> newCoord: newCoords)
        {
            bool found = false;
            for(vector<int> uniqueNewCoord : uniqueNewCoords)
            {
                if(newCoord[0]==uniqueNewCoord[0] && newCoord[1]==uniqueNewCoord[1])
                {
                    found = true;
                }
            }

            if(!found)
            {
                uniqueNewCoords.push_back(newCoord);
            }
        }

        coords = uniqueNewCoords;
//        printGarden(garden, coords);
        cout << "Step: " << step << endl;
    }

    cout << "Day 21 Part 1: " << coords.size() << endl;
    return coords.size();
}