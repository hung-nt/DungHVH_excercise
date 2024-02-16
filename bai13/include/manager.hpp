#ifndef _MANAGER_HPP_
#define _MANAGER_HPP_
#include "Employee.hpp"
#include <iostream>
#include "manager.hpp"
#include <vector>
#include <algorithm>
#include"certificate.hpp"
#include "Experience.hpp"
#include "fresher.hpp"
#include "intern.hpp"
using namespace std;
class UIManager {
    
private:
    std::vector<Employee*> employees;
    
public:
    static long count;
    void insertEmployee(int employeeType);

    void searchEmployee(const int& employeeId);

    void deleteEmployee(const int& employeeId);

    void showAllEmployees();
    ~UIManager();
};
#endif //_MANAGER_HPP_