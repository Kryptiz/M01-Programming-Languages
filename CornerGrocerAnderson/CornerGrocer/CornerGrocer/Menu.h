/*
 * File:        Menu.h
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Declares the MenuOption choices and the Menu class, which handles all
 *   user input.
 */

#ifndef MENU_H
#define MENU_H

#include <string>

// The choices the user can make from the menu.
enum MenuOption {
    LOOKUP_ITEM = 1,
    PRINT_ALL = 2,
    PRINT_HISTOGRAM = 3,
    EXIT_PROGRAM = 4
};

// Responsible for all user input: showing the menu, validating the choice,
// and asking for an item name.
class Menu {
public:
    // Prints the menu options.
    void Display() const;

    // Asks until the user enters a valid option (1-4), then returns it.
    MenuOption GetChoice() const;

    // Asks the user for an item name and returns it.
    std::string PromptForItem() const;
};

#endif