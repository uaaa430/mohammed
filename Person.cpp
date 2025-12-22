#include "Person.h"
#include <algorithm>
#include <iomanip>
#include <numeric>

Person::Person() : exam(0), finalGrade(0.0) {}

Person::Person(const std::string& n, const std::string& s)
    : name(n), surname(s), exam(0), finalGrade(0.0) {}

Person::Person(const Person& other)
    : name(other.name),
      surname(other.surname),
      homework(other.homework),
      exam(other.exam),
      finalGrade(other.finalGrade) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }
    return *this;
}

Person::~Person() {
    homework.clear();
}

void Person::calculateFinal(bool useMedian) {
    double hwResult;

    if (useMedian) {
        std::sort(homework.begin(), homework.end());
        size_t n = homework.size();
        hwResult = (n % 2 == 0)
            ? (homework[n / 2 - 1] + homework[n / 2]) / 2.0
            : homework[n / 2];
    } else {
        hwResult = std::accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    }

    finalGrade = 0.4 * hwResult + 0.6 * exam;
}

std::istream& operator>>(std::istream& in, Person& p) {
    in >> p.name >> p.surname;

    p.homework.clear();
    int hw;
    while (in >> hw && hw != -1) {
        p.homework.push_back(hw);
    }

    in >> p.exam;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << std::left << std::setw(12) << p.name
        << std::setw(15) << p.surname
        << std::fixed << std::setprecision(2)
        << p.finalGrade;
    return out;
}
