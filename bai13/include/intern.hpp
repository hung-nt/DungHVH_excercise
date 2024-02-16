#ifndef _INTERN_HPP_
#define _INTERN_HPP_
#include <string>
#include "employee.hpp"
#include<iostream>

/*****************************************************************
__Intern___*******************************************************
******************************************************************/

class Intern : public Employee {
private:
    std::string major;
    int semester;
    std::string universityName;

public:
    Intern() {}

    Intern(const std::string& major, int semester, const std::string& universityName)
        : major(major), semester(semester), universityName(universityName) {}

    Intern(int& id, const std::string& fullName, const std::string& birthday, const std::string& phone, const std::string& email, const std::vector<Certificate>& certificates, const std::string& major, int semester, const std::string& universityName)
        : Employee(id, fullName, birthday, phone, email, certificates), major(major), semester(semester), universityName(universityName) {}

    void showInformation();

    std::string getMajor() const {
        return major;
    }

    void setMajor(const std::string& major) {
        this->major = major;
    }

    int getSemester() const {
        return semester;
    }

    void setSemester(int semester) {
        this->semester = semester;
    }

    std::string getUniversityName() const {
        return universityName;
    }

    void setUniversityName(const std::string& universityName) {
        this->universityName = universityName;
    }
};
#endif //_ITERN_HPP_