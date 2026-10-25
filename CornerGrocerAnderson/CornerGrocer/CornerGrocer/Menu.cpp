/*
 * File:        Menu.cpp
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Implements Menu. Displays the menu, validates the user's choice
 *   (1-4), and prompts for an item name.
 */

#include "Menu.h"

#include <iostream>
#include <sstream>

void Menu::Display() const {
    std::cout << "\n===== Corner Grocer =====\n"
              << LOOKUP_ITEM     << ". Look up an item's frequency\n"
              << PRINT_ALL       << ". Print all item frequencies\n"
              << PRINT_HISTOGRAM << ". Print histogram\n"
              << EXIT_PROGRAM    << ". Exit\n";
}

MenuOption Menu::GetChoice() const {
    // Input validation: keep asking until the user enters 1-4.
    while (true) {
        std::cout << "Enter your choice (1-4): ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            return EXIT_PROGRAM;  // input stream closed; exit gracefully
        }
        std::istringstream parser(line);
        int choice = 0;
        char extra;
        if ((parser >> choice) && !(parser >> extra) &&
            choice >= LOOKUP_ITEM && choice <= EXIT_PROGRAM) {
            return static_cast<MenuOption>(choice);
        }
        std::cout << "Invalid input. Please enter a number from 1 to 4.\n";
    }
}

std::string Menu::PromptForItem() const {
    std::cout << "Enter the item to look up: ";
    std::string item;
    std::getline(std::cin, item);
    return item;
}