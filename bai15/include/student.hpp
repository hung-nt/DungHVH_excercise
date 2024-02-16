#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include "main.hpp"
#include "SemesterResult.hpp"

using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    string birthDate;
    int enrollmentYear;
    float entranceScore;
    vector<SemesterResult> results;
public:
    static int fulltime_student_count;

    Student() = default;
    virtual ~Student() = default;

    Student(string id, string name, string dob, int year, float score)
        : studentID(id), fullName(name), birthDate(dob), enrollmentYear(year), entranceScore(score) {}

    Student(const Student& other);

    void input();

    void output() const;

    float getAverageScoreBySemester(const string& semester) const;

    string getFullName();

    float getEntranceScore();

    int getEnrollmentYear();

    void addSemesterResult(SemesterResult);
};

#endif /* __STUDENT_HPP__ */