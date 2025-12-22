#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person {
private:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int exam{};
    double finalGrade{};

public:
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    void calculateFinal(bool useMedian = false);
    double getFinal() const;
    std::string getName() const;
    std::string getSurname() const;

    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
};

#endif
