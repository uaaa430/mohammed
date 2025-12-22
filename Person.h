#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person {
private:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Person();
    Person(const std::string& n, const std::string& s);

    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    void calculateFinal(bool useMedian);

    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
};

#endif
