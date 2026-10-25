/*
 * File:        BackupFile.cpp
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Implements BackupFile. Writes every item and its count to
 *   frequency.dat.
 */

#include "BackupFile.h"

#include <fstream>

BackupFile::BackupFile(const std::string& fileName) : fileName(fileName) {}

bool BackupFile::Write(const ItemCounter& counter) const {
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        return false;
    }
    for (const auto& entry : counter.GetAllCounts()) {
        outFile << entry.first << " " << entry.second << "\n";
    }
    return true;
}