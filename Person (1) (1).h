#include "Lib.h"

class Timer {
public:
    using ClockType = std::chrono::high_resolution_clock;
    std::chrono::time_point<ClockType> startTime, endTime;
    std::chrono::duration<double> elapsed;

    void start();
    void stop();
};

void printHeader();
void generateFile(const std::string& filename, size_t n);

class Person {
public:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int examScore;
    double finalAverage;
    double finalMedian;

    void calculateAverage();
    double calculateMedianValue() const;
    void calculateMedianFinal();

    Person();
    Person(const std::string& n, const std::string& s,
           const std::vector<int>& hw, int ex);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);
};

#endif
