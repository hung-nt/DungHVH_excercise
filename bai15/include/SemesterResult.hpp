#ifndef __SEMESTERRESULT_HPP__
#define __SEMESTERRESULT_HPP__

#include "main.hpp"

using namespace std;

class SemesterResult {
private:
    string semesterName;
    float averageScore;
public:
    SemesterResult() = default;

    SemesterResult(string name, float score) : semesterName(name), averageScore(score) {}

    void input();

    void output() const;

    string getSemesterName() const;

    float getAverageScore() const;
};

#endif /* __SEMESTERRESULT_HPP__ */