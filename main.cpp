#include "Person.h"
#include "Lib.h"

int main() {
    int count;

    std::cout << "Enter number of students: ";
    std::cin >> count;

    // Allocate list of students
    std::vector<Person> list(count);

    // Input section
    for (int i = 0; i < count; ++i) {
        std::cout << "\n--- Student " << (i + 1) << " ---\n";
        std::cin >> list[i];
    }

    // Header line
    std::cout << std::left
              << std::setw(15) << "Name"
              << std::setw(15) << "Surname"
              << std::setw(20) << "Final (Avg.)"
              << std::setw(15) << "Final (Med.)"
              << "\n";

    std::cout << "---------------------------------------------------------------\n";

    // Output students
    for (const auto& st : list) {
        std::cout << st << "\n";
    }

    return 0;
}


