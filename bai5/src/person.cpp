#include"person.hpp"
/************************************************
 * person*****************************************/

Person::Person(string name, int age, string passport, Room* room, int numberRent) {
    this->name = name;
    this->age = age;
    this->passport = passport;
    this->numberRent = numberRent;
    this->room = room;
}

int Person::getNumberRent() {
    return numberRent;
}

void Person::setNumberRent(int numberRent) {
    this->numberRent = numberRent;
}

string Person::getName() {
    return name;
}

void Person::setName(string name) {
    this->name = name;
}

int Person::getAge() {
    return age;
}

void Person::setAge(int age) {
    this->age = age;
}

string Person::getPassport() {
    return passport;
}

void Person::setPassport(string passport) {
    this->passport = passport;
}

Room* Person::getRoom() {
    return room;
}

void Person::setRoom(Room* room) {
    this->room = room;
}

string Person::toString() {

    return "Person{ Name=" + name  + ", age=" + to_string(age) +", passport='" + passport + "\'," + room->toString() + " }";
}