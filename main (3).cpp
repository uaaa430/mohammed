#include "FileManager.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>

int main() {
    try {
        generateFile("students10000.txt", 10000);

        std::vector<Person> students;

        auto start = std::chrono::high_resolution_clock::now();

        readFile("students10000.txt", students);

        std::sort(students.begin(), students.end(),
            [](const Person& a, const Person& b) {
                return a.getSurname() < b.getSurname();
            });

        splitAndWrite(students);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        std::cout << "Total time: " << diff.count() << " s\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
