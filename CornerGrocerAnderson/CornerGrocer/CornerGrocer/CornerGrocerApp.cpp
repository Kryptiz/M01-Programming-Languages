/*
 * File:        CornerGrocerApp.cpp
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Implements CornerGrocerApp. The constructor loads the purchase log
 *   and creates the frequency.dat backup. Run() shows the menu and
 *   handles each choice until the user exits.
 */

#include "CornerGrocerApp.h"

#include <iostream>

CornerGrocerApp::CornerGrocerApp(const std::string& inputFileName)
    : backup("frequency.dat"), loaded(counter.LoadFromFile(inputFileName)) {
    if (!loaded) {
        std::cout << "Error: could not open " << inputFileName << "\n";
        return;
    }
    // Backup is created at startup with no user action.
    if (!backup.Write(counter)) {
        std::cout << "Error: could not create frequency.dat\n";
    }
}

void CornerGrocerApp::Run() {
    if (!loaded) {
        return;
    }
    MenuOption choice;
    do {
        menu.Display();
        choice = menu.GetChoice();
        switch (choice) {
            case LOOKUP_ITEM:     printer.PrintItem(menu.PromptForItem(), counter); break;
            case PRINT_ALL:       printer.PrintAll(counter);                        break;
            case PRINT_HISTOGRAM: printer.PrintHistogram(counter);                  break;
            case EXIT_PROGRAM:    std::cout << "Goodbye!\n";                        break;
        }
    } while (choice != EXIT_PROGRAM);
}