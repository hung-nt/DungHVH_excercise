#ifndef _EMPLOYEE_HPP_
#define _EMPLOYEE_HPP_
#include<vector>
#include"certificate.hpp"

class Employee {
    
    // Assuming Employee class is defined elsewhere with appropriate members and methods
protected:
    int id;
    std::string fullName;
    std::string birthday; // Using std::tm to represent date
    std::string phone;
    std::string email;
    std::vector<Certificate> certificates;
public:

    // Constructors, member functions, etc. for Employee
    Employee() {};
    Employee(int id, std::string fullName, std::string birthday, std::string phone, std::string email, std::vector<Certificate> certificates);

    virtual void showInformation(); // Pure virtual function for abstract method

    int getId() const;
    void setId(const int &id);
    std::string getFullName() const;
    void setFullName(const std::string &fullName);
    std::string getBirthday() const;

    void setBirthday(const std::string &birthday);
    std::string getPhone() const;
    void setPhone(const std::string &phone);
    std::string getEmail() const;
    void setEmail(const std::string &email);
    virtual ~Employee() = default;
};
#endif //_EMPLOYEE_HPP_