#include "Person.h"
#include "Lib.h"


int main() {
    generateFile("students10000.txt", 10000);
    generateFile("students100000.txt", 100000);
    generateFile("students1000000.txt", 1000000);
    generateFile("students10000000.txt", 10000000);

    std::vector<Person> passedStudents;
    std::vector<Person> failedStudents;

    Timer timer;

    try {
        timer.start();

        std::ifstream inFile("Students.txt");
        std::cout << "Time taken to open file: " << std::endl;
        timer.stop();

        if (!inFile) throw std::runtime_error("Cannot open Students.txt");

        std::string headerLine;
        if (!std::getline(inFile, headerLine)) throw std::runtime_error("Failed to read header row");

        std::vector<Person> students;
        Person temp;

        while (inFile >> temp) {
            students.push_back(temp);
        }

        timer.start();
        std::sort(students.begin(), students.end(), [](const Person& a, const Person& b) {
            return a.name < b.name;
        });
        std::cout << "Time taken to sort file: " << std::endl;
        timer.stop();

        timer.start();
        for (const auto& s : students) {
            if (s.finalAverage >= 5 || s.finalMedian >= 5)
                passedStudents.push_back(s);
            else
                failedStudents.push_back(s);
        }
        std::cout << "Time taken to split students: " << std::endl;
        timer.stop();

        timer.start();
        std::cout << "PASSED" << std::endl;
        printHeader();

        std::ofstream passFile("passed.txt");
        std::ofstream failFile("failed.txt");

        for (const auto& s : passedStudents) {
            passFile << s;
            std::cout << s << std::endl;
        }

        std::cout << "FAILED" << std::endl;
        printHeader();

        for (const auto& s : failedStudents) {
            failFile << s;
            std::cout << s << std::endl;
        }

        std::cout << "Time taken to write output files: " << std::endl;
        timer.stop();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
