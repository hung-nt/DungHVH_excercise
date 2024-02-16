#include "main.hpp"

using namespace std;

FullTimeStudent::FullTimeStudent(string id, string name, string dob, int year, float score)
    : Student(id, name, dob, year, score) {
    fulltime_student_count++;
}