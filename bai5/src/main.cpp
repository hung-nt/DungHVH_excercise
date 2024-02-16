#include <iostream>
#include <vector>
#include<algorithm>
#include"Room.hpp"
#include"person.hpp"
#include"hotel.hpp"






class RoomA : public Room {
public:
    RoomA() : Room("A", 500) {}
    string toString() {
        return "RoomA{category='" + category + "', price=" + std::to_string(price) + '}';
    }
};

class RoomB : public Room {
public:
    RoomB() : Room("B", 300) {}
    string toString() {
        return "RoomB{category='" + category + "', price=" + std::to_string(price) + '}';
    }
};

class RoomC : public Room {
public:
    RoomC() : Room("C", 100) {}
    string toString() {
        return "RoomC{category='" + category + "', price=" + std::to_string(price) + '}';
    }

};
/************************************************
 * Main*****************************************/

int main() {
    Hotel hotel;
    while (true) {
        cout << "Application Manager Candidate" << endl;
        cout << "Enter 1: To insert person for rent" << endl;
        cout << "Enter 2: To remove person by passport" << endl;
        cout << "Enter 3: To calculator price by passport" << endl;
        cout << "Enter 4: To show infor" << endl;
        cout << "Enter 5: To exit:" << endl;
        string line;
        getline(cin, line);
        if (line == "1") {
            cout << "Enter name: ";
            string fullname;
            getline(cin, fullname);
            cout << "Enter age: ";
            int age;
            cin >> age;
            cout << "Enter passport: ";
            cin.ignore();
            string passport;
            getline(cin, passport);
            cout << "Choise a to rent room type A" << endl;
            cout << "Choise b to rent room type B" << endl;
            cout << "Choise c to rent room type C" << endl;
            string choise;
            getline(cin, choise);
            Room* room;
            if (choise == "a") {
                room = new RoomA();
            } else if (choise == "b") {
                room = new RoomB();
            } else if (choise == "c") {
                room = new RoomC();
            } else {
                continue;
            }
            cout << "Enter number day for rent: ";
            int numberRent;
            cin >> numberRent;
            Person person(fullname, age, passport, room, numberRent);
            hotel.add(person);
            cin.ignore();
        } else if (line == "2") {
            cout << "Enter passport: ";
            string passport;
            getline(cin, passport);
            hotel.delete1(passport);
        } else if (line == "3") {
            cout << "Enter passport: ";
            string passport;
            getline(cin, passport);
            cout << "Price: " << hotel.calculator(passport) << endl;
        } else if (line == "4") {
            hotel.show();
        } else if (line == "5") {
            return 0;
        } else {
            cout << "Invalid" << endl;
            continue;
        }
    }
}
