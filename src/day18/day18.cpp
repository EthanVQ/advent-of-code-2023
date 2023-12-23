//
// Created by Ethan Jones on 18/12/2023.
//

#include "day18.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "../tools.h"
#include <map>
#include <vector>

using namespace std;

static map<string, vector<long>> directionMapper = { {"U", {0, 1}}, {"D", {0, -1}}, {"L", {-1, 0}}, {"R", {1, 0}} };
static map<char, string> partTwoDirectionMapper = { {'0', "R"}, {'1', "D"}, {'2', "L"}, {'3', "U"} };

tuple<long, long, tuple<long, long>>  getTrenchSize(vector<tuple<string, long, string>> digPlan)
{
    long X = 0;
    long Y = 0;

    long minX = 0;
    long maxX = 0;
    long minY = 0;
    long maxY = 0;

    for(tuple<string, long, string> digStep : digPlan)
    {
        vector<long> direction = directionMapper[get<0>(digStep)];
        long length = get<1>(digStep);

        X += direction[0]*length;
        Y += direction[1]*length;

        if(X < minX)
        {
            minX = X;
        }

        if(X > maxX)
        {
            maxX = X;
        }

        if(Y < minY)
        {
            minY = Y;
        }

        if(Y > maxY)
        {
            maxY = Y;
        }
    }

    return  {maxX - minX + 1, maxY - minY + 1, {-minX, -minY}};
}



tuple<long, long> getFloodFillStart(vector<vector<int>> trench)
{
    // scan along the edges until there is a dot

    for(long i = 0; i < trench.size(); i ++)
    {
        for(long j = 0; j < trench[0].size(); j++)
        {
            if(i == 0)
            {
                if(trench[i][j] == 1 && trench[i+1][j] == 0)
                {
                    return {i+1, j};
                }
            }

            if(j == 0)
            {
                if(trench[i][j] == 1 && trench[i][j+1] == 0)
                {
                    return {i, j+1};
                }
            }

            if(i == trench.size()-1)
            {
                if(trench[i][j] == 1 && trench[i-1][j] == 0)
                {
                    return {i-1, j};
                }
            }

            if(j == trench[0].size()-1)
            {
                if(trench[i][j] == 1 && trench[i][j-1] == 0)
                {
                    return {i, j-1};
                }
            }
        }
    }
    return {};
}

void floodFillTrench(vector<vector<int>> &trench, long X, long Y, long offsetX, long offsetY)
{
    long indexX = X + offsetX;
    long indexY = Y + offsetY;
    if(indexX < 0 || indexY < 0 || indexY >= trench[0].size() || indexX >= trench.size())
    {
        return;
    }

    if(trench[X+offsetX][Y+offsetY] == 0)
    {
        trench[X+offsetX][Y+offsetY] = 1;
        floodFillTrench(trench, X+1, Y, offsetX, offsetY);
        floodFillTrench(trench, X-1, Y, offsetX, offsetY);
        floodFillTrench(trench, X, Y+1, offsetX, offsetY);
        floodFillTrench(trench, X, Y-1, offsetX, offsetY);
    }
}

int countArea(vector<vector<int>> trench)
{
    int count = 0;
    for(vector<int> row : trench)
    {
        for (int i = 0; i < row.size(); ++i) {
            if(row[i]==1)
            {
                count++;
            }
        }
    }

    return count;
}

void printTrench(vector<vector<int>> trench)
{
    cout << endl;

    for(vector<int> row : trench)
    {
        for (int i = 0; i < row.size(); ++i) {
            if(row[i]==1)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int day18::part1() {

    // read fi;e

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day18/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    string line;
    vector<tuple<string, long, string>> digPlan;

    while (getline(inputFile, line)) {
        vector<string> splitElements = tools::splitStringBySeparator(line, ' ');
        tuple<string, long, string> digStep = { splitElements[0], stol(splitElements[1]), splitElements[2]};
        digPlan.push_back(digStep);
    }

    // get dig plan

    long X = 0;
    long Y = 0;

    tuple<long, long, tuple<long, long>> trenchDetails = getTrenchSize(digPlan);
    tuple<long, long> trenchOffset = get<2>(trenchDetails);
    long offsetX = get<0>(trenchOffset);
    long offsetY = get<1>(trenchOffset);
    tuple<long, long> trenchSize = { get<0>(trenchDetails), get<1>(trenchDetails) };
    vector<vector<int>> trench(get<0>(trenchSize), vector<int>(get<1>(trenchSize), 0)); // set value to 1 to count

    for(tuple<string, long, string> digStep : digPlan)
    {
        // take a step base on direction and pass through
        vector<long> direction = directionMapper[get<0>(digStep)];
        long length = get<1>(digStep);

        for(long i = 0; i < length; i++)
        {
            X += direction[0];
            Y += direction[1];
            trench[X + offsetX][Y + offsetY] = 1;
        }
    }

    printTrench(trench);

    // flood fill from start

    tuple<long, long> start = getFloodFillStart(trench);
    X = get<0>(start) - offsetX;
    Y = get<1>(start) - offsetY;

    cout << "Starting point: (" << X << ", " << Y << ")" << endl;

    floodFillTrench(trench, X, Y, offsetX, offsetY);

    printTrench(trench);

    cout << "Day 18 Part 1: " << countArea(trench) << endl;
}




