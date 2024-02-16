#include "main.hpp"

using namespace std;

void SemesterResult::input() {
    cout << "Enter semester name: ";
    cin >> semesterName;
    cout << "Enter average score: ";
    cin >> averageScore;
}

void SemesterResult::output() const {
    cout << "Semester: " << semesterName << ", Average Score: " << averageScore << endl;
}

string SemesterResult::getSemesterName() const {
    return semesterName;
}

float SemesterResult::getAverageScore() const {
    return averageScore;
}