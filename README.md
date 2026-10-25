# Corner Grocer Item-Tracking Program

**CS 210 Project Three** | William Anderson | Instructor: Bary Pollack

A C++ console application that reads a grocery purchase log and reports how often each item was bought.

## Features

| Menu Option | What it does |
| --- | --- |
| 1 | Look up the purchase count for a single item (case-insensitive; returns 0 if the item is absent) |
| 2 | List every item with its frequency |
| 3 | Print a histogram with one asterisk per purchase |
| 4 | Exit |

- The purchase log is read at startup, and a `frequency.dat` backup file is written automatically.
- Menu input is validated, so invalid entries are re-prompted instead of crashing the program.

## Design

The program is split into five classes, each with one job:

- **ItemCounter**: holds the item data (private `std::map`, accessed through public methods)
- **BackupFile**: writes `frequency.dat`
- **ReportPrinter**: displays frequencies and the histogram
- **Menu**: handles user input and validation
- **CornerGrocerApp**: coordinates the other classes, which keeps `main()` to three lines

`std::map` was chosen because counting is simply `++counts[item]` and it keeps items sorted for display.

## Reflection

### Summarize the project and the problem it was solving

Corner Grocer needed a quick way to see which items sell most often so they could arrange the produce section accordingly. This program reads their daily purchase log, counts how many times each item appears, and lets the user query those counts through a simple menu.

### What did I do particularly well?

I think the design came out especially well. Splitting the program into five focused classes kept each piece easy to understand and kept `main()` extremely small. I used encapsulation (private data members reached only through public methods) so other classes cannot change the counts, and I used `const` methods that do not modify data. Choosing `std::map` made the counting logic simple and gave sorted output for free. I also added input validation so bad menu entries are re-prompted rather than crashing the program.

### Where could I enhance my code?

- **Error handling and security:** Report a clear message if the input file is missing or malformed instead of assuming clean data, and validate item names read from the file.
- **Flexibility:** Accept the input file name from the user or a configuration setting rather than hard-coding it.
- **Testing:** Add unit tests for `ItemCounter` so changes to the counting logic can be verified automatically.

These changes would make the program more robust, easier to adapt to new data, and safer to modify.

### Which pieces were most challenging, and how did I overcome them?

The hardest parts were deciding how to divide responsibilities across classes without making them too dependent on each other, and making item lookup case-insensitive while returning 0 for absent items. I worked through these by building and testing one small piece at a time against the sample input before moving on. I relied on course materials, C++ reference documentation, and my instructor and classmates for support.

### What skills are transferable to other projects or coursework?

- Breaking a program into focused, single-purpose classes
- Using encapsulation to protect data
- Choosing the right data structure for the job
- Validating user input
- Commenting and documenting code clearly

These apply to any future object-oriented project or course.

### How did I make the program maintainable, readable, and adaptable?

Every class and method is commented, names are descriptive, and each class has a narrow responsibility. Because of that, changes stay local: a new report format only touches `ReportPrinter`, and a change to how data is saved only touches `BackupFile`.
