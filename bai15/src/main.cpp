#include "main.hpp"

using namespace std;

int main() {
    Department computerScience("Computer Science");

    FullTimeStudent student1("CS001", "Nguyen Van A", "01/01/2000", 2022, 8.5);
    student1.addSemesterResult(SemesterResult("20231", 8.8));
    student1.addSemesterResult(SemesterResult("20222", 8.3));
    computerScience.addStudent(&student1);

    PartTimeStudent student2("CS002", "Nguyen Van B", "02/02/2001", 2023, 7.5, "Dong Nai");
    student2.addSemesterResult(SemesterResult("20231", 7.8));
    student2.addSemesterResult(SemesterResult("20222", 7.2));
    computerScience.addStudent(&student2);

    FullTimeStudent student3("CS003", "Nguyen Van C", "03/03/1999", 2019, 9.0);
    student3.addSemesterResult(SemesterResult("20231", 9.2));
    student3.addSemesterResult(SemesterResult("20222", 8.7));
    computerScience.addStudent(&student3);

    cout << "Full-time students count: " << Student::fulltime_student_count << endl;

    Student* highestEntranceScoreStudent = computerScience.findStudentWithHighestEntranceScore();
    if (highestEntranceScoreStudent) {
        cout << "Student with the highest entrance score: " << highestEntranceScoreStudent->getFullName() << endl;
    }

    vector<PartTimeStudent*> partTimeStudentsInDongNai = computerScience.getPartTimeStudentsByLocation("Dong Nai");
    cout << "Part-time students in Dong Nai:" << endl;
    for (const auto& student : partTimeStudentsInDongNai) {
        cout << student->getFullName() << endl;
    }

    vector<Student*> highScoreStudents = computerScience.getStudentsWithHighAverageScore(8.0);
    cout << "Students with high average score in the last semester:" << endl;
    for (const auto& student : highScoreStudents) {
        cout << student->getFullName() << endl;
    }

    Student* highestAverageScoreStudent = computerScience.getStudentWithHighestAverageScore();
    if (highestAverageScoreStudent) {
        cout << "Student with the highest average score: " << highestAverageScoreStudent->getFullName() << endl;
    }

    computerScience.countStudentsByEnrollmentYear();

    return 0;
}