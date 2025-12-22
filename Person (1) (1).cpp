#include "Person.h"
#include <algorithm>
#include <numeric>
#include <random>
#include <iomanip>

Person::Person() : exam(0), finalGrade(0.0) {}

Person::Person(const Person& o)
    : name(o.name), surname(o.surname),
      homework(o.homework), exam(o.exam),
      finalGrade(o.finalGrade) {}

Person& Person::operator=(const Person& o) {
    if (this != &o) {
        name = o.name;
        surname = o.surname;
        homework = o.homework;
        exam = o.exam;
        finalGrade = o.finalGrade;
    }
    return *this;
}

Person::~Person() {}

void Person::generateRandom() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> d(1, 10);

    homework.clear();
    for (int i = 0; i < 5; i++)
        homework.push_back(d(gen));

    exam = d(gen);
}

void Person::calculateFinal() {
    double avg = std::accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    finalGrade = 0.4 * avg + 0.6 * exam;
}

double Person::getFinal() const { return finalGrade; }
std::string Person::getName() const { return name; }
std::string Person::getSurname() const { return surname; }

std::istream& operator>>(std::istream& in, Person& p) {
    in >> p.name >> p.surname;
    p.homework.resize(5);
    for (int& h : p.homework) in >> h;
    in >> p.exam;
    p.calculateFinal();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << std::left << std::setw(12) << p.name
        << std::setw(12) << p.surname
        << std::fixed << std::setprecision(2)
        << p.finalGrade;
    return out;
}
