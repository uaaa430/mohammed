#include "Person.h"

void Timer::startTimer() {
    start = Clock::now();
}

void Timer::stopTimer() {
    auto end = Clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << duration.count() << " ms" << endl;
}

void printHeader() {
    cout << left << setw(15) << "Name"
         << setw(15) << "Surname"
         << setw(20) << "Final (Avg.)"
         << setw(5) << "|" << "Final (Med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void generateFile(const string& filename, size_t n) {
    ofstream out(filename);
    out << "Name" << setw(10) << "Surname"
        << setw(10) << "HW1" << setw(5) << "HW2" << setw(5) << "HW3"
        << setw(5) << "HW4" << setw(5) << "HW5" << setw(5) << "Exam" << endl;

    srand(static_cast<unsigned int>(time(0)));

    for (size_t i = 1; i <= n; ++i) {
        vector<int> hw(5);
        for (int j = 0; j < 5; ++j) {
            hw[j] = rand() % 10;
        }
        int examGrade = rand() % 10;
        out << "Name" << i << setw(10)
            << "Surname" << i << setw(10)
            << hw[0] << setw(5) << hw[1] << setw(5) << hw[2]
            << setw(5) << hw[3] << setw(5) << hw[4] << setw(5) << examGrade << endl;
    }
}

void Person::computeAverage() {
    if (Homework.empty()) {
        FinalgradeAvg = 0;
        return;
    }
    double avg = accumulate(Homework.begin(), Homework.end(), 0.0) / Homework.size();
    FinalgradeAvg = avg * 0.4 + exam * 0.6;
}

double Person::computeMedian() const {
    if (Homework.empty()) return 0.0;
    vector<int> temp = Homework;
    sort(temp.begin(), temp.end());
    size_t n = temp.size();
    return (n % 2 == 0) ? (temp[n / 2 - 1] + temp[n / 2]) / 2.0 : temp[n / 2];
}

void Person::computeMedianFinal() {
    FinalgradeMed = computeMedian() * 0.4 + exam * 0.6;
}

Person::Person() {
    firstname = "Test";
    surname = "Test";
    Homework = {9, 9, 9, 9, 9, 9};
    FinalgradeAvg = 0;
    FinalgradeMed = 0;
}

Person::Person(const string& f, const string& s, const vector<int>& hw, int ex) {
    firstname = f;
    surname = s;
    Homework = hw;
    exam = ex;
    FinalgradeAvg = 0;
    FinalgradeMed = 0;
}

Person::Person(const Person& other) {
    firstname = other.firstname;
    surname = other.surname;
    Homework = other.Homework;
    exam = other.exam;
    FinalgradeAvg = other.FinalgradeAvg;
    FinalgradeMed = other.FinalgradeMed;
}

Person::~Person() {
    Homework.clear();
    firstname.clear();
    surname.clear();
    FinalgradeAvg = 0;
    FinalgradeMed = 0;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstname = other.firstname;
        surname = other.surname;
        Homework = other.Homework;
        exam = other.exam;
        FinalgradeAvg = other.FinalgradeAvg;
        FinalgradeMed = other.FinalgradeMed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << left << setw(15) << p.firstname
       << setw(15) << p.surname
       << fixed << setprecision(2)
       << setw(20) << p.FinalgradeAvg
       << setw(5) << "|" << p.FinalgradeMed;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    is >> p.firstname >> p.surname;
    p.Homework.clear();

    for (int i = 0; i < 5; ++i) {
        int grade;
        is >> grade;
        p.Homework.push_back(grade);
    }

    is >> p.exam;
    p.computeAverage();
    p.computeMedianFinal();

    return is;
}
