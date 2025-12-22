#include "StudentManager.h"
#include "Timer.h"
#include <iostream>

int main() {
    try {
        StudentManager manager;

        // Generate file
        {
            Timer t("File generation");
            manager.generateRandomFile("students100000.txt", 100000);
        }

        // Vector example
        {
            Timer t("Vector read");
            manager.readFromFile("students100000.txt",'v');

            std::vector<Person> passedVec, failedVec;
            Timer t2("Vector split Strategy1");
            manager.splitStrategy1(manager.studentsVec, passedVec, failedVec);

            Timer t3("Vector output");
            manager.writeToFile("passed_vector.txt", passedVec);
            manager.writeToFile("failed_vector.txt", failedVec);
        }

        // List example
        {
            Timer t("List read");
            manager.readFromFile("students100000.txt",'l');

            std::list<Person> failedList;
            Timer t2("List split Strategy2");
            manager.splitStrategy2(manager.studentsList, failedList);

            Timer t3("List output");
            manager.writeToFile("failed_list.txt", failedList);
            manager.writeToFile("passed_list.txt", manager.studentsList);
        }

        // Deque example
        {
            Timer t("Deque read");
            manager.readFromFile("students100000.txt",'d');

            std::deque<Person> passedDeque, failedDeque;
            Timer t2("Deque split Strategy1");
            manager.splitStrategy1(manager.studentsDeque, passedDeque, failedDeque);

            Timer t3("Deque output");
            manager.writeToFile("passed_deque.txt", passedDeque);
            manager.writeToFile("failed_deque.txt", failedDeque);
        }

    } catch(const std::exception& e){
        std::cerr << "ERROR: " << e.what() << "\n";
    }
}
