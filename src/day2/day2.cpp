//
// Created by Ethan Jones on 05/12/2023.
//

#include "day2.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "../tools.h"
#include <map>

using namespace std;

int day2::part1() {

    // read and parse file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day2/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    std::string line;

    vector<vector<map<string, long>>> games;

    while (getline(inputFile, line)) {

        string gameString = line.substr(line.find(":") + 1);

        vector<string> handStrings = tools::splitStringBySeparator(gameString, ';');

        vector<map<string, long>> game;

        for(const string& handString : handStrings) {

            vector<string> colorStrings = tools::splitStringBySeparator(handString, ',');

            map<string, long> hand { { "red", 0}, {"blue", 0}, {"green", 0} };

            for(const string& colorString : colorStrings) {

                string trimmedColorString = tools::trimWhitespace(colorString);

                vector<string> numberAndColor = tools::splitStringBySeparator(trimmedColorString, ' ');

                hand[numberAndColor[1]] = stol(numberAndColor[0]);
            }

            game.push_back(hand);
        }

        games.push_back(game);
    }

    inputFile.close();

    // solve

    int answer = 0;

    int gameNumber = 1;

    for(const vector<map<string, long>>& hands : games)
    {
        bool gamePossible = true;
        for(const map<string, long>& hand : hands)
        {
            for (auto & it : hand) {
                if(it.first == "red" && it.second > 12)
                {
                    gamePossible = false;
                    break;
                }
                if(it.first == "green" && it.second > 13)
                {
                    gamePossible = false;
                    break;
                }
                if(it.first == "blue" && it.second > 14)
                {
                    gamePossible = false;
                    break;
                }
            }
            if(!gamePossible)
            {
                break;
            }
        }
        if(gamePossible)
        {
            answer += gameNumber;
        }
        gameNumber++;
    }

    cout << "Day 2 Part 1: " << answer << endl;

    return 0;
}

int day2::part2() {
    // read and parse file

    ifstream inputFile("/Users/ejones/Documents/GitHub/advent-of-code-2023/src/day2/puzzle.txt");

    if (!inputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    std::string line;

    vector<vector<map<string, long>>> games;

    while (getline(inputFile, line)) {

        string gameString = line.substr(line.find(":") + 1);

        vector<string> handStrings = tools::splitStringBySeparator(gameString, ';');

        vector<map<string, long>> game;

        for(const string& handString : handStrings) {

            vector<string> colorStrings = tools::splitStringBySeparator(handString, ',');

            map<string, long> hand { { "red", 0}, {"blue", 0}, {"green", 0} };

            for(const string& colorString : colorStrings) {

                string trimmedColorString = tools::trimWhitespace(colorString);

                vector<string> numberAndColor = tools::splitStringBySeparator(trimmedColorString, ' ');

                hand[numberAndColor[1]] = stol(numberAndColor[0]);
            }

            game.push_back(hand);
        }

        games.push_back(game);
    }

    inputFile.close();

    // solve

    int answer = 0;

    for(const vector<map<string, long>>& hands : games)
    {
        map<string, long > minimumSet { { "red", 0}, {"blue", 0}, {"green", 0} };

        for(const map<string, long>& hand : hands)
        {
            for (auto & it : hand) {
                if(it.second > minimumSet[it.first])
                {
                    minimumSet[it.first] = it.second;
                }
            }
        }

        answer += minimumSet["red"] * minimumSet["green"] * minimumSet["blue"];
    }

    cout << "Day 2 Part 2: " << answer << endl;

    return 0;
}