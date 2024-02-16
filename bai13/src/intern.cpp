#include "intern.hpp"

void Intern::showInformation() {
    Employee::showInformation();
    std::cout <<
        "\n major='" << major << '\'' <<
        "\n semester=" << semester <<
        "\n universityName='" << universityName << '\'' <<
        '}';
}