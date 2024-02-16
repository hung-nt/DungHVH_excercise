#ifndef _EXP_HPP_
#define _EXP_HPP_
#include<iostream>
#include "employee.hpp"


class Experience : public Employee {
    private:
        int yearOfExperience;
        std::string proSkill;

    public:
        Experience() {}

        Experience(int yearOfExperience, std::string proSkill)
            : yearOfExperience(yearOfExperience), proSkill(proSkill) {}

        Experience(int id, std::string fullName, std::string birthday, std::string phone, std::string email, std::vector<Certificate> certificates, int yearOfExperience, std::string proSkill)
            : Employee(id, fullName, birthday, phone, email, certificates), yearOfExperience(yearOfExperience), proSkill(proSkill) {}

        void showInformation() override;

        int getYearOfExperience() const {
            return yearOfExperience;
        }

        void setYearOfExperience(int yearOfExperience) {
            this->yearOfExperience = yearOfExperience;
        }

        std::string getProSkill() const {
            return proSkill;
        }

        void setProSkill(const std::string &proSkill) {
            this->proSkill = proSkill;
        }      
};


#endif //_EXP_HPP_