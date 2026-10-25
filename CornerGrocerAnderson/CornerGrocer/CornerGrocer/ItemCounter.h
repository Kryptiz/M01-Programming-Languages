/*
 * File:        ItemCounter.h
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Declares the ItemCounter class, which stores how many times each item
 *   was purchased.
 */


#ifndef ITEM_COUNTER_H
#define ITEM_COUNTER_H

#include <map>
#include <string>

// Holds the data: how many times each item was purchased.
// Knows how to load the purchase log and answer count queries.
class ItemCounter {
public:
    // Reads the purchase log and counts each item. Returns false if the file can't be opened.
    bool LoadFromFile(const std::string& fileName);

    // Returns how many times an item was purchased (case-insensitive, 0 if never).
    int GetCount(const std::string& item) const;

    // Read-only access to every item and its count (sorted alphabetically).
    const std::map<std::string, int>& GetAllCounts() const;

private:
    // Returns a lowercase copy of a string for case-insensitive matching.
    static std::string ToLower(const std::string& text);

    std::map<std::string, int> counts;  // item name -> times purchased
};

#endif