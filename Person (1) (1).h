#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person {
private:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Person();
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    void generateRandom();
    void calculateFinal();

    double getFinal() const;
    std::string getName() const;
    std::string getSurname() const;

    friend std::istream& operator>>(std::istream&, Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&);
};

#endif
