#include "manager.hpp"
Intern* new_Intern;
Fresher* new_fresher;
Experience* new_exp;
void UIManager::insertEmployee(int employeeType) 
{
    // employees.push_back(employee);
    // std::cout << "Employee added successfully!" << std::endl;
    int ID = 0;
    string fullName;
    string birthDay;
    string phone;
    string email;
    int id_cer;
    std::string name_cer;
    std::string rank_cer;
    std::string date_cer;
    
    count ++;
    // int count_id = 1;
    ID = count;

    cout << "Enter employee's full name." << endl;
    getline(cin, fullName);

    cout << "Enter employee's birthday. Follow format yyyy-mm-dd." << endl;
    getline(cin, birthDay);

    cout << "Enter employee's phone." << endl;
    getline(cin, phone);

    cout << "Enter employee's email." << endl;
    getline(cin, email);
    // cin.ignore();
    cout<<"Enter your number  certificate:\n";
    int var;
    cin >> var;
    cin.ignore();

    std::vector<Certificate> vector_certificate;
    while(var>=1)
    {
        id_cer=var;

        cout << "Enter name of certificate "<<var << endl;
        getline(cin, name_cer);

        cout << "Enter rank of certificate "<<var << endl;
        getline(cin,rank_cer);

        cout << "Enter date of certificate "<<var << endl;
        getline(cin,date_cer);


        Certificate* new_Cer = new Certificate(id_cer,name_cer,rank_cer,date_cer);
        vector_certificate.push_back(*new_Cer);
        delete new_Cer;
        var--;
    }

    switch (employeeType)
    {
        case 1:
        {
            int expInYear;
            string proSkill;
            cout << "Enter employee's ExpInYear." << endl;
            cin >> expInYear;
            cin.ignore();

            cout << "Enter employee's ProSkill." << endl;
            getline(cin,proSkill);

            new_exp = new Experience(ID,fullName,birthDay,phone,email,vector_certificate,expInYear,proSkill);
            employees.push_back(new_exp);
            new_exp=nullptr;
            // delete new_exp;
            break;
        }

        
        case 2:
        {
            std::string graduationDate;
            std::string graduationRank;
            std::string universityName;
            cout << "Enter employee's graduation date:" << endl;
            getline(cin,graduationDate);

            cout << "Enter employee's graduation rank:" << endl;
            getline(cin,graduationRank);

            cout << "Enter employee's university name." << endl;
            getline(cin,universityName);

            new_fresher = new Fresher(ID,fullName,birthDay,phone,email,vector_certificate,graduationDate,graduationRank,universityName);
            employees.push_back(new_fresher);
            new_fresher = nullptr;
            // delete new_fresher;
            break;
        }
        
        case 3:
        {
            string major;
            int semester;
            string university;
            cout << "Enter employee's major." << endl;
            getline(cin,major);

            cout << "Enter employee's semester." << endl;
            cin >> semester;
            cin.ignore();

            cout << "Enter employ's university." << endl;
            getline(cin,university);
            new_Intern = new Intern(ID,fullName,birthDay,phone,email,vector_certificate,major,semester,university);
            employees.push_back(new_Intern);
            new_Intern = nullptr;
            break;
        }   
        default:
        {
            
            break;
        }
    }

}


void UIManager::searchEmployee(const int& employeeId) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [employeeId](const Employee* emp) { return emp->getId() == employeeId; });

    if (it != employees.end()) {
        (*it)->showInformation();
    } else {
        std::cout << "Employee with ID " << employeeId << " not found." << std::endl;
    }
}

void UIManager::deleteEmployee(const int& employeeId) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [employeeId](const Employee* emp) { return emp->getId() == employeeId; });

    if (it != employees.end()) {
        employees.erase(it);
        count--;
        for (auto i = employees.begin(); i != employees.end(); i++) {
            (*i)->setId(i - employees.begin() + 1);
        }
    } else {
        std::cout << "Employee with ID " << employeeId << " not found." << std::endl;
    }
}

void UIManager::showAllEmployees() {
    std::cout << "List of all employees:" << std::endl;
    for (const auto& emp : employees) {
        emp->showInformation();
        std::cout << "\n--------------------------" << std::endl;
    }
}

UIManager::~UIManager() {
    // Clean up allocated memory for employees
    for (auto& emp : employees) {
        delete emp;
    }
}


long UIManager::count=0;