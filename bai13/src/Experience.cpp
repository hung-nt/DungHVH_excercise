#include "Experience.hpp"


void Experience::showInformation() {
    Employee::showInformation();
    std::cout <<"\n yearOfExperience=" << getYearOfExperience() <<
    "\n proSkill='" << getProSkill() << '\'' <<
    '}';
}
