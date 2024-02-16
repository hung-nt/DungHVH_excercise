#include "main.hpp"

using namespace std;

int Student::fulltime_student_count = 0;

Student::Student(const Student& other) {
    studentID = other.studentID;
    fullName = other.fullName;
    birthDate = other.birthDate;
    enrollmentYear = other.enrollmentYear;
    entranceScore = other.entranceScore;
    results = other.results;
}

void Student::input() {
    cout << "Enter student ID: ";
    cin >> studentID;
    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "Enter birthdate (dd/mm/yyyy): ";
    cin >> birthDate;
    cout << "Enter enrollment year: ";
    cin >> enrollmentYear;
    cout << "Enter entrance score: ";
    cin >> entranceScore;

    int numOfResults;
    cout << "Enter number of semester results: ";
    cin >> numOfResults;
    for (int i = 0; i < numOfResults; ++i) {
        SemesterResult result;
        result.input();
        results.push_back(result);
    }
}

void Student::output() const {
    cout << "Student ID: " << studentID << ", Name: " << fullName << ", Birthdate: " << birthDate
                << ", Enrollment Year: " << enrollmentYear << ", Entrance Score: " << entranceScore << endl;

    cout << "Semester Results:" << endl;
    for (const auto& result : results) {
        result.output();
    }
}

float Student::getAverageScoreBySemester(const string& semester) const {
    for (const auto& result : results) {
        if (result.getSemesterName() == semester) {
            return result.getAverageScore();
        }
    }
    return 0;
}

string Student::getFullName() {
    return fullName;
}

float Student::getEntranceScore() {
    return entranceScore;
}

int Student::getEnrollmentYear() {
    return enrollmentYear;
}

void Student::addSemesterResult(SemesterResult inputResult) {
    results.push_back(inputResult);
}