#include"hotel.hpp"
#include<algorithm>



/************************************************
 * hotel*****************************************/


void Hotel::add(Person person) {
    this->persons.push_back(person);
}

bool Hotel::delete1(string passport) {
    auto it = find_if(this->persons.begin(), this->persons.end(), [&passport](Person p) { return p.getPassport() == passport; });
    if (it == this->persons.end()) {
        return false;
    } else {
        this->persons.erase(it);
        return true;
    }
}

int Hotel::calculator(string passport) {
    auto it = find_if(this->persons.begin(), this->persons.end(), [&passport](Person p) { return p.getPassport() == passport; });
    if (it == this->persons.end()) {
        return 0;
    }
    return it->getRoom()->getPrice() * it->getNumberRent();
}

void Hotel::show() {
    for (Person p : this->persons) {
        cout << p.toString() << endl;
    }
}