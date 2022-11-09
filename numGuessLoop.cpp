// Copyright (c) 2022 KestrelBryce All rights reserved
//
// Created by: KestrelBryce
// Created on: Nov 8, 2022
// This program asks for a guess
// between 0 and 9, and tells the user if
// their number is the same as the
// computer-generated answer

#include <time.h>

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

int main() {
    // Declaring variables
    std::string userGuessString;
    int userGuessInt, correctGuess;

    // initializing random seed
    std::random_device rseed;

    std::mt19937 rgen(rseed());

    // initializing random number code
    std::uniform_int_distribution<int> idist(0, 9);

    // making random number variable
    correctGuess = idist(rgen);

    // Introductory paragraph
    std::cout << "This program asks for a guess\n";
    std::cout << "between 0 and 9, and tells the user if\n";
    std::cout << "their number is the same as the\n";
    std::cout << "computer-generated answer\n";
    std::cout << "\n";

    // Starting loop
    while (true) {
        std::cout << "Enter a number (0-9): ";
        std::cin >> userGuessString;

        // Process
        // Checking that userNum is an integer
        try {
            userGuessInt = std::stoi(userGuessString);

            // Checking that userGuessInt is in the right range
            if (userGuessInt >= 0 && userGuessInt <= 9) {
                // Checking to see if userGuessInt is correct
                if (userGuessInt == correctGuess) {
                    // output
                    std::cout << "You guessed correctly!";
                    break;
                } else {
                    std::cout << "You guessed incorrectly.";
                    std::cout << "The correct number was ";
                    std::cout << correctGuess << ".\n";
                }
            } else {
                std::cout << "Please enter a whole number from 0-9.";
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter a valid integer.";
        }
    }
}
