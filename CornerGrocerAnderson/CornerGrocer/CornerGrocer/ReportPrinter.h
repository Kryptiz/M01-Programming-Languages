/*
 * File:        ReportPrinter.h
 * Name:        William Anderson
 * Course:      CS 210
 * Instructor:  Bary Pollack
 * Date:        October 17, 2026
 * Project:     Project Three - Corner Grocer
 *
 * Description:
 *   Declares the ReportPrinter class, which prints item frequency reports.
 */

#ifndef REPORT_PRINTER_H
#define REPORT_PRINTER_H

#include "ItemCounter.h"

// Responsible for everything printed about the data:
// single-item results, the full list, and the histogram.
class ReportPrinter {
public:
    // Prints "item count" for one item.
    void PrintItem(const std::string& item, const ItemCounter& counter) const;

    // Prints every item with its count.
    void PrintAll(const ItemCounter& counter) const;

    // Prints every item followed by one asterisk per purchase.
    void PrintHistogram(const ItemCounter& counter) const;

private:
    static const char kHistogramSymbol = '*';
};

#endif