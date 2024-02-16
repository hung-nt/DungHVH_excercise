#ifndef _HOTEL_HPP_
#define _HOTEL_HPP_
#include<vector>
#include"person.hpp"
#include<iostream>
using namespace std;
/************************************************
 * hotel*****************************************/

class Hotel {
    private:
        vector<Person> persons;
    public:
        Hotel()=default;

        void add(Person person);

        bool delete1(string passport);

        int calculator(string passport);

        void show();
};
#endif//_HOTEL_HPP_