#include "Person.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <stdexcept>

Person::Person() = default;
Person::~Person() = default;
Person::Person(const Person& other) = default;
Person& Person::operator=(const Person& other) = default;

void Person::calculateFinal(bool useMedian) {
    if (homework.empty())
        throw std::runtime_error("No homework data");

    double hwValue;
    if (useMedian) {
        std::vector<int> temp = homework;
        std::sort(temp.begin(), temp.end());
        size_t n = temp.size();
        hwValue = (n % 2 == 0) ? (temp[n/2-1] + temp[n/2]) / 2.0 : temp[n/2];
    } else {
        hwValue = std::accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    }
    finalGrade = 0.4 * hwValue + 0.6 * exam;
}

double Person::getFinal() const { return finalGrade; }
std::string Person::getName() const { return name; }
std::string Person::getSurname() const { return surname; }

std::istream& operator>>(std::istream& in, Person& p) {
    p.homework.clear();
    in >> p.name >> p.surname;

    int x;
    for (int i = 0; i < 5; ++i) {
        if (!(in >> x)) throw std::runtime_error("Invalid homework input");
        p.homework.push_back(x);
    }
    in >> p.exam;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << std::left << std::setw(10) << p.name
        << std::setw(15) << p.surname
        << std::fixed << std::setprecision(2) << p.finalGrade;
    return out;
}
