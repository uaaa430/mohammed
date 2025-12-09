#ifndef PERSON_H
#define PERSON_H

#include "Lib.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>

class Person {
public:
    // Basic identity info
    std::string name;
    std::string surname;

    // Grade storage
    std::vector<int> hw;
    int exam{};

    // Final grade results
    double avgResult{};
    double medResult{};

    // Constructors
    Person();
    Person(const std::string& n, const std::string& s,
           const std::vector<int>& homework, int examScore);

    // Rule of 3
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    // Grade computation
    void computeAverage();
    void computeMedian();

    // Helper
    double getMedianValue() const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
    friend std::istream& operator>>(std::istream& in, Person& p);
};

#endif
