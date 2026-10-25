/*
 * File:        ReportPrinter.cpp
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Implements ReportPrinter. Prints a single item's count, the full list
 *   of item counts, and the asterisk histogram.
 */

#include "ReportPrinter.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

void ReportPrinter::PrintItem(const std::string& item, const ItemCounter& counter) const {
    std::cout << item << " " << counter.GetCount(item) << "\n";
}

void ReportPrinter::PrintAll(const ItemCounter& counter) const {
    for (const auto& entry : counter.GetAllCounts()) {
        std::cout << entry.first << " " << entry.second << "\n";
    }
}

void ReportPrinter::PrintHistogram(const ItemCounter& counter) const {
    // Find the longest name so the asterisks line up.
    size_t width = 0;
    for (const auto& entry : counter.GetAllCounts()) {
        width = std::max(width, entry.first.size());
    }
    for (const auto& entry : counter.GetAllCounts()) {
        std::cout << std::left << std::setw(static_cast<int>(width) + 1) << entry.first
                  << std::string(entry.second, kHistogramSymbol) << "\n";
    }
}