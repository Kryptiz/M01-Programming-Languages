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

#include "ItemCounter.h"

#include <algorithm>
#include <cctype>
#include <fstream>

bool ItemCounter::LoadFromFile(const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        return false;
    }
    std::string item;
    while (inFile >> item) {
        ++counts[item];  // map creates the entry at 0 if the item is new
    }
    return true;
}

int ItemCounter::GetCount(const std::string& item) const {
    const std::string target = ToLower(item);
    // Linear search so matching ignores letter case.
    for (const auto& entry : counts) {
        if (ToLower(entry.first) == target) {
            return entry.second;
        }
    }
    return 0;
}

const std::map<std::string, int>& ItemCounter::GetAllCounts() const {
    return counts;
}

std::string ItemCounter::ToLower(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}