#include "main.hpp"

using namespace std;

void Department::addStudent(Student* student) {
    students.push_back(student);
}

Student* Department::findStudentWithHighestEntranceScore() const {
    if (students.empty()) {
        return nullptr;
    }

    auto maxEntranceScoreStudent = students[0];
    for (const auto& student : students) {
        if (student->getEntranceScore() > maxEntranceScoreStudent->getEntranceScore()) {
            maxEntranceScoreStudent = student;
        }
    }
    return maxEntranceScoreStudent;
}

vector<PartTimeStudent*> Department::getPartTimeStudentsByLocation(const string& location) const {
    vector<PartTimeStudent*> partTimeStudents;
    for (const auto& student : students) {
        auto partTimeStudent = dynamic_cast<PartTimeStudent*>(student);
        if (partTimeStudent && partTimeStudent->getTrainingLocation() == location) {
            partTimeStudents.push_back(partTimeStudent);
        }
    }
    return partTimeStudents;
}

vector<Student*> Department::getStudentsWithHighAverageScore(float threshold) const {
    vector<Student*> highScoreStudents;
    for (const auto& student : students) {
        float lastSemesterScore = student->getAverageScoreBySemester("20231");
        if (lastSemesterScore >= threshold) {
            highScoreStudents.push_back(student);
        }
    }
    return highScoreStudents;
}

Student* Department::getStudentWithHighestAverageScore() const {
    if (students.empty()) {
        return nullptr;
    }

    auto maxAverageScoreStudent = students[0];
    for (const auto& student : students) {
        float maxScore = student->getAverageScoreBySemester("20231");
        if (maxScore > maxAverageScoreStudent->getAverageScoreBySemester("20231")) {
            maxAverageScoreStudent = student;
        }
    }
    return maxAverageScoreStudent;
}

void Department::countStudentsByEnrollmentYear() const {
    cout << "Student count by enrollment year:" << endl;
    map<int, int> enrollmentYearCount;
    for (const auto& student : students) {
        enrollmentYearCount[student->getEnrollmentYear()]++;
    }

    for (const auto& entry : enrollmentYearCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}