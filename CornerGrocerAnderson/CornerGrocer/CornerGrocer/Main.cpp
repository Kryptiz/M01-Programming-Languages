/*
 * File:        main.cpp
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Entry point of the program. Creates the CornerGrocerApp with the
 *   purchase log file name and starts it. All other work is handled by
 *   the classes.
 */



#include "CornerGrocerApp.h"

int main() {
    CornerGrocerApp app("CS210_Project_Three_Input_File.txt");
    app.Run();
    return 0;
}