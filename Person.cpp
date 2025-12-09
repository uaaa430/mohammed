#include "Person.h"

Person::Person() {
    name = "Test";
    surname = "Test";
    hw = {9, 9, 9, 9, 9};
    exam = 0;
}

Person::Person(const std::string& n, const std::string& s, const std::vector<int>& h, int ex) {
    name = n;
    surname = s;
    hw = h;
    exam = ex;
}

Person::Person(const Person& other) {
    name = other.name;
    surname = other.surname;
    hw = other.hw;
    exam = other.exam;
    finalAvg = other.finalAvg;
    finalMed = other.finalMed;
}

Person::~Person() {
    hw.clear();
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        hw = other.hw;
        exam = other.exam;
        finalAvg = other.finalAvg;
        finalMed = other.finalMed;
    }
    return *this;
}

void Person::calcAvg() {
    if (hw.empty()) {
        finalAvg = exam * 0.6;
        return;
    }

    double sum = std::accumulate(hw.begin(), hw.end(), 0.0);
    double average = sum / hw.size();
    finalAvg = average * 0.4 + exam * 0.6;
}

double Person::computeMedian() const {
    if (hw.empty()) return 0.0;

    std::vector<int> temp = hw;
    std::sort(temp.begin(), temp.end());

    size_t n = temp.size();
    if (n % 2 == 0)
        return (temp[n/2 - 1] + temp[n/2]) / 2.0;
    return temp[n/2];
}

void Person::calcMed() {
    finalMed = computeMedian() * 0.4 + exam * 0.6;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << std::left << std::setw(15) << p.name
        << std::setw(15) << p.surname
        << std::fixed << std::setprecision(2)
        << std::setw(20) << p.finalAvg
        << std::setw(15) << p.finalMed;

    return out;
}

std::istream& operator>>(std::istream& in, Person& p) {
    std::cout << "Enter firstname: ";
    in >> p.name;

    std::cout << "Enter surname: ";
    in >> p.surname;

    p.hw.clear();
    char option;

    std::cout << "1. Enter 'R' for random grades\n";
    std::cout << "2. Enter 'S' to input grades manually\n";
    in >> option;

    if (option == 'R' || option == 'r') {
        std::srand(std::time(nullptr));
        for (int i = 0; i < 5; i++)
            p.hw.push_back(std::rand() % 10 + 1);

        p.exam = std::rand() % 10 + 1;
    }
    else if (option == 'S' || option == 's') {
        std::cout << "Enter homework grades (negative number to finish):\n";
        int g;
        while (true) {
            in >> g;
            if (g < 0) break;
            p.hw.push_back(g);
        }
        std::cout << "Enter exam grade: ";
        in >> p.exam;
    }
    else {
        std::cout << "Invalid choice.\n";
    }

    char method;
    std::cout << "Choose calculation method (A = Average, M = Median): ";
    in >> method;

    if (method == 'A' || method == 'a')
        p.calcAvg();
    else
        p.calcMed();

    return in;
}
