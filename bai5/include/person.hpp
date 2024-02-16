#ifndef _PERSON_HPP_
#define _PERSON_HPP_
/************************************************
 * person*****************************************/
#include<string>
#include"Room.hpp"
using namespace std;
class Person {
    private:
        string name;
        int age;
        string passport;
        Room* room;
        int numberRent;
    public:
        Person();
        Person(string name, int age, string passport, Room* room, int numberRent);

        int getNumberRent();

        void setNumberRent(int numberRent);

        string getName();

        void setName(string name);

        int getAge();

        void setAge(int age);

        string getPassport();

        void setPassport(string passport);

        Room* getRoom();

        void setRoom(Room* room);

        string toString();

};
#endif//_PERSON_HPP_