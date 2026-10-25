/*
 * File:        CornerGrocerApp.h
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Declares the CornerGrocerApp class, which ties the other classes
 *   together and runs the program.
 */

#ifndef CORNER_GROCER_APP_H
#define CORNER_GROCER_APP_H

#include <string>
#include "BackupFile.h"
#include "ItemCounter.h"
#include "Menu.h"
#include "ReportPrinter.h"

// Ties the other classes together and runs the program.
class CornerGrocerApp {
public:
    // Loads the purchase log and creates the backup file.
    explicit CornerGrocerApp(const std::string& inputFileName);

    // Runs the menu loop until the user chooses to exit.
    void Run();

private:
    ItemCounter counter;
    BackupFile backup;
    ReportPrinter printer;
    Menu menu;
    bool loaded;  // true if the input file was read successfully
};

#endif