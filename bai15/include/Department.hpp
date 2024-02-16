#ifndef __DEPARTMENT_HPP__
#define __DEPARTMENT_HPP__

#include "main.hpp"
#include "Student.hpp"
#include "PartTimeStudent.hpp"

using namespace std;

class Department {
private:
    string departmentName;
    vector<Student*> students;
public:
    Department(string name) : departmentName(name) {}

    void addStudent(Student* student);

    Student* findStudentWithHighestEntranceScore() const;

    vector<PartTimeStudent*> getPartTimeStudentsByLocation(const string& location) const;

    vector<Student*> getStudentsWithHighAverageScore(float threshold) const;

    Student* getStudentWithHighestAverageScore() const;

    void countStudentsByEnrollmentYear() const;
};

#endif /* __DEPARTMENT_HPP__ */