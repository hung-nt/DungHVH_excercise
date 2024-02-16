#include<iostream>
#include"employee.hpp"


/*******************************************************************
___Employee__*******************************************************
********************************************************************/


Employee::Employee(int id, std::string fullName, std::string birthday, std::string phone, std::string email, std::vector<Certificate> certificates)
    : id(id), fullName(fullName), birthday(birthday), phone(phone), email(email), certificates(certificates) {}
void Employee::showInformation(){
    std::cout<<"Employee "<< id <<"{" <<
        "id= \'" << id << '\'' <<
        "\n fullName='" << getFullName() << '\'' <<
        "\n birthday=" << getBirthday() << // Assuming getBirthday() returns a std::tm
        "\n phone='" << getPhone() << '\'' <<
        "\n email='" << getEmail() << '\'';
    std::cout<<"\n certificate= " <<"{";
    for(const auto& ce:certificates)
    {

        std::cout<<"Id " << ce.getId()<<"= {" <<" Date= "<<ce.getDate()<<'\''<<", Rank= "<<ce.getRank()<<'\''<< ", name= "<<ce.getName()<<"}";
    }
    std::cout<<"}";
};

int Employee:: getId() const {
    return id;
}
void Employee:: setId(const int &id) {
    this->id = id;
}
std::string Employee:: getFullName() const {
    return fullName;
}
void Employee:: setFullName(const std::string &fullName) {
    this->fullName = fullName;
}
std::string Employee:: getBirthday() const {
    return birthday;
}

void Employee:: setBirthday(const std::string &birthday) {
    this->birthday = birthday;
}
std::string Employee:: getPhone() const {
    return phone;
}
void Employee:: setPhone(const std::string &phone) {
    this->phone = phone;
}
std::string Employee:: getEmail() const {
    return email;
}
void Employee:: setEmail(const std::string &email) {
    this->email = email;
}


