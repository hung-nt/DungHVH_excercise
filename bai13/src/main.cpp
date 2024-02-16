#include <iostream>
#include"certificate.hpp"
#include <string>
#include <vector>
#include"manager.hpp"
#include"fresher.hpp"
#include "Experience.hpp"
#include "intern.hpp"




/*****************************************************************
___BirthDayException__********************************************
******************************************************************/

class BirthDayException : public std::runtime_error {
public:
    BirthDayException(const std::string& message) : std::runtime_error(message) {}
};


/*****************************************************************
__EmailException___***********************************************
******************************************************************/

class EmailException : public std::exception {
    // You can add functionality to your custom exception if needed
};


/*****************************************************************
__FullNameException___********************************************
******************************************************************/

class FullNameException : public std::exception {
private:
    std::string message;
public:
    FullNameException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};


/*****************************************************************
__PhoneException___***********************************************
******************************************************************/

class PhoneException : public std::exception {
private:
    std::string message;
public:
    PhoneException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};




/*****************************************************************
__main___*********************************************************
******************************************************************/

class ScannerFactory {
public:
    static std::istream& getScanner() {
        return std::cin;
    }
};

int main() {
    UIManager uiManager;
    std::istream& scanner = ScannerFactory::getScanner();
    int choice;
    int employeeId_search;
    int employeeId_delete;

    while (true) {
        std::cout << "Company Employee Management System" << std::endl;
        std::cout << "1. Insert Employee" << std::endl;
        std::cout << "2. Search Employee" << std::endl;
        std::cout << "3. Show All Employees" << std::endl;
        std::cout << "4. Delete Employees" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        scanner >> choice;
        scanner.ignore();

        switch (choice) {
            case 1: {
                system("cls");
                int employeeType;
                std::cout << "1.Experience\n2.Fresher\n3.Intern\nEnter employee type : ";
                scanner >> employeeType;
                scanner.ignore();
                if(employeeType != 1 && employeeType !=2 && employeeType != 3)
                {
                    cout<<"Input is invalid\n";
                    break;
                }
                
                uiManager.insertEmployee(employeeType);
                
                break;
            }
            case 2:
                system("cls");
                std::cout << "Enter employee ID to search: ";
                scanner >> employeeId_search;
                scanner.ignore();
                uiManager.searchEmployee(employeeId_search);
                break;
            case 3:
                system("cls");
                uiManager.showAllEmployees();
                break;
            case 4:
                system("cls");
                std::cout<<"Enter of Id student:";
                scanner >> employeeId_delete;
                scanner.ignore();
                uiManager.deleteEmployee(employeeId_delete);

                break;

            case 5:
                system("cls");
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    //comment

    return 0;
    //why notw
}