#ifndef __PARTTIMESTUDENT_HPP__
#define __PARTTIMESTUDENT_HPP__

#include "main.hpp"

using namespace std;

class PartTimeStudent : public Student {
private:
    string trainingLocation;
public:
    PartTimeStudent() = default;

    PartTimeStudent(string id, string name, string dob, int year, float score, string location)
        : Student(id, name, dob, year, score), trainingLocation(location) {}

    PartTimeStudent(const PartTimeStudent& other) : Student(other) {
    trainingLocation = other.trainingLocation;
}

    string getTrainingLocation();
};

#endif /* __PARTTIMESTUDENT_HPP__ */