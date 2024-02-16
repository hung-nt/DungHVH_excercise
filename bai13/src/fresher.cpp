#include"fresher.hpp"

Fresher::Fresher(std::string graduationDate, std::string graduationRank, std::string universityName)
    : graduationDate(graduationDate), graduationRank(graduationRank), universityName(universityName) {}

Fresher::Fresher(int id, std::string fullName, std::string birthday, std::string phone, std::string email, std::vector<Certificate> certificates, std::string graduationDate, std::string graduationRank, std::string universityName)
    : Employee(id, fullName, birthday, phone, email, certificates), graduationDate(graduationDate), graduationRank(graduationRank), universityName(universityName) {}

void Fresher::showInformation() {
    Employee::showInformation();
    std::cout << 
        "\n graduationDate=" << getGraduationDate() <<
        "\n graduationRank='" << graduationRank << '\'' <<
        "\n universityName='" << universityName << '\'' <<
        '}';
}

std::string Fresher::getGraduationDate() const {
    return graduationDate;
}

void Fresher::setGraduationDate(std::string graduationDate) {
    this->graduationDate = graduationDate;
}

std::string Fresher::getGraduationRank() const {
    return graduationRank;
}

void Fresher::setGraduationRank(std::string graduationRank) {
    this->graduationRank = graduationRank;
}

std::string Fresher::getEducation() const {
    return universityName;
}

void Fresher::setEducation(std::string education) {
    this->universityName = education;
}
