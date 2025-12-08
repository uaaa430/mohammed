#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <iostream>
class Person {
public:
    std::string name, surname;
    std::vector<double> homeworks;
    double exam, finalGrade;
    Person();
    Person(const std::string&, const std::string&);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();
    friend std::istream& operator>>(std::istream&, Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&);
    void calculateFinal(bool useMedian) noexcept;
    double computeAverage() const noexcept;
    double computeMedian() const noexcept;
};
#endif
