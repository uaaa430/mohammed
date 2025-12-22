#include "Person.h"
#include <vector>
#include <iostream>
#include <iomanip>

int main() {
    std::vector<Person> students;
    int n;
    bool useMedian;

    std::cout << "Use median (1=yes, 0=no): ";
    std::cin >> useMedian;

    std::cout << "Number of students: ";
    std::cin >> n;

    std::cout << "Enter data: Name Surname HW1 HW2 ... HWn -1 Exam\n";

    for (int i = 0; i < n; i++) {
        Person p;
        std::cin >> p;
        p.calculateFinal(useMedian);
        students.push_back(p);
    }

    std::cout << std::left
              << std::setw(12) << "Name"
              << std::setw(15) << "Surname"
              << "Final_Point"
              << std::endl;

    std::cout << "----------------------------------------" << std::endl;

    for (const auto& s : students) {
        std::cout << s << std::endl;
    }

    return 0;
}


