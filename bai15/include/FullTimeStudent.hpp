#ifndef __FULLTIMESTUDENT_HPP__
#define __FULLTIMESTUDENT_HPP__

#include "main.hpp"

using namespace std;

class FullTimeStudent : public Student {
public:
    FullTimeStudent() = default;

    FullTimeStudent(string id, string name, string dob, int year, float score);
};

#endif /* __FULLTIMESTUDENT_HPP__ */