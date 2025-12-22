#include "Person.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<Person> students;
    int n;
    bool useMedian;

    std::cout << "Use median (1=yes, 0=no): ";
    std::cin >> useMedian;

    std::cout << "Number of students: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Person p;
        std::cin >> p;
        p.calculateFinal(useMedian);
        students.push_back(p);
    }

    for (const auto& s : students) {
        std::cout << s << std::endl;
    }

    return 0;
}
