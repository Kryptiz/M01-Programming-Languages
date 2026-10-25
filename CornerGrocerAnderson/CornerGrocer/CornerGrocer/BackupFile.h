/*
 * File:        ItemCounter.cpp
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Implements ItemCounter. Reads the purchase log into a map, counts
 *   each item, and returns counts for lookups (case-insensitive).
 */


#ifndef BACKUP_FILE_H
#define BACKUP_FILE_H

#include <string>
#include "ItemCounter.h"

// Saving the item counts to a backup file (frequency.dat).
class BackupFile {
public:
    explicit BackupFile(const std::string& fileName);

    // Writes every item and its count to the file. Returns false on failure.
    bool Write(const ItemCounter& counter) const;

private:
    std::string fileName;
};

#endif