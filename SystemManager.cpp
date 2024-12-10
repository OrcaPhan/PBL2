//SystemManager.cpp:
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<thread>
#include<chrono>
#include <iomanip> 
#include"People.h"
#include"Staff.h"
#include"Payroll.h"
#include"Attendance.h"
#include"SystemManager.h"

using namespace std;

double t;

SystemManager::SystemManager() : head(nullptr), tail(nullptr) { }

SystemManager::~SystemManager() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->staff;
        delete current;
        current = next;
    }
}

void SystemManager::append(Staff* sta) {
    Node* new_node = new Node(sta);
    if (tail == nullptr) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void SystemManager::remove(string staffcode) {
    Node* current = head;
    while (current != nullptr) {
        if (current->staff->getStaffCode() == staffcode) {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            if (current->next != nullptr)
                current->next->prev = current->prev;
            if (current == head)
                head = current->next;
            if (current == tail)
                tail = current->prev;
            delete current->staff;
            delete current;
            printTabs(4); cout << "Employee removed successfully!" << endl;
            return;
        }
        current = current->next;
    }
    printTabs(4); cout << "Employee not found!" << endl;
}

Staff* SystemManager::findByStaffCode(const string& staffcode) {
    Node* current = head;
    while (current != nullptr) {
        if (current->staff->getStaffCode() == staffcode) {
            return current->staff;
        }
        current = current->next;
    }  
    return nullptr;
}

void SystemManager::displayByStaffCode(const string& staffcode) {
    Staff* staff = findByStaffCode(staffcode);
    if (staff) {
        staff->DisplayInfor();
    } else {
        printTabs(4); cout << "No employee found with staff code: " << staffcode << endl;
    }
}

vector<Staff*> SystemManager::findByFullName(const string& fullname) {
    vector<Staff*> result;
    Node* current = head;
    while (current != nullptr) {
        if (current->staff->getFullName() == fullname) {
            result.push_back(current->staff);
        }
        current = current->next;
    }
    return result;
}

void SystemManager::displayByFullName(const string& fullname) {
    vector<Staff*> staffList = findByFullName(fullname);
    if (staffList.empty()) {
        printTabs(4); cout << "No employee found with name: " << fullname << endl;
        return;
    }
    if (staffList.size() == 1) {
        staffList[0]->DisplayInfor();
        return;
    }
    printTabs(4); cout << "Multiple employees found with name: " << fullname << endl;
    for (size_t i = 0; i < staffList.size(); i++) {
        printTabs(4); cout << " " << i + 1 << ". StaffCode: " << staffList[i]->getStaffCode() << endl;
    }
    printTabs(4); cout << "Enter the index of the employee you want to view: ";
    int choice;
    cin >> choice;
    if (choice > 0 && choice <= staffList.size()) {
        staffList[choice - 1]->DisplayInfor();
    } else {
        printTabs(4); cout << "Invalid choice!" << endl;
    }
}

void SystemManager::updateInfor(string staffcode, const Staff& updatestaff) {
    Staff* staff = findByStaffCode(staffcode);
    if (staff != nullptr) {
        int update_choice;
        bool continue_update = true;
        while (continue_update) {
            system("cls");
            printTabs(4); cout << "The information the employee found: " << endl;
            staff->DisplayInfor();
                          cout << endl;
            printTabs(4); cout << "Select field to update:" << endl;
            printTabs(4); cout << "1 . Full Name" << endl;
            printTabs(4); cout << "2 . Gender" << endl;
            printTabs(4); cout << "3 . Date of Birth" << endl;
            printTabs(4); cout << "4 . Phone Number" << endl;
            printTabs(4); cout << "5 . Address Email" << endl;
            printTabs(4); cout << "6 . Position" << endl;
            printTabs(4); cout << "7 . Department" << endl;
            printTabs(4); cout << "8 . Day Off" << endl;
            printTabs(4); cout << "9 . Review" << endl;
            printTabs(4); cout << "10. Salary Coefficient" << endl;
            printTabs(4); cout << "11. Basic Salary" << endl;
            printTabs(4); cout << "0 . Back" << endl;
            printTabs(4); cout << "Enter choice: ";
            cin >> update_choice;
            
            string fullName, gender, birthDate, phoneNumber, addressEmail, position, department;
            float salaryCoefficient;
            double basicSalary;
            int dayOff;
            double review;
            switch (update_choice) {
                case 1:
                    printTabs(4); cout << "New Full Name: ";
                    cin.ignore();
                    getline(cin, fullName);
                    staff->setFullName(fullName);
                    break;
                case 2:
                    printTabs(4); cout << "New Gender: ";                    
                    cin.ignore();
                    getline(cin, gender);
                    staff->setGender(gender);
                    break;
                case 3:
                    printTabs(4); cout << "New Date of Birth: ";
                    cin >> birthDate;
                    staff->setBirthDate(birthDate);
                    break;
                case 4:
                    printTabs(4); cout << "New Phone Number: ";
                    cin.ignore();
                    getline(cin, phoneNumber);
                    staff->setPhoneNumber(phoneNumber);
                    break;
                case 5:
                    printTabs(4); cout << "New Address Email: ";
                    cin.ignore();
                    getline(cin, addressEmail);
                    staff->setAddressEmail(addressEmail);
                    break;
                case 6:
                    printTabs(4); cout << "New Position: ";
                    cin.ignore();
                    getline(cin, position);
                    staff->setPosition(position);
                    break;
                case 7:
                    printTabs(4); cout << "New Department: ";
                    cin.ignore();
                    getline(cin, department);
                    staff->setDepartment(department);
                    break;
                case 8:
                    printTabs(4); cout << "New Day Off: ";
                    cin >> dayOff;
                    staff->setDayOff(dayOff);
                    break;
                case 9:
                    printTabs(4); cout << "New Review: ";
                    cin >> review;
                    staff->setReview(review);
                    break;
                case 10:
                    printTabs(4); cout << "New Salary Coefficient: ";
                    cin >> salaryCoefficient;
                    staff->setSalaryCoefficient(salaryCoefficient);
                    break;
                case 11:
                    printTabs(4); cout << "New Basic Salary: ";
                    cin >> basicSalary;
                    staff->setBasicSalary(basicSalary);
                    break;
                case -1: 
                case 0:
                    continue_update = false;
                    break;
                default:
                    printTabs(4); cout << "Invalid choice!" << endl;
            }
            if (continue_update) {
                char more_update;
                printTabs(4); cout << "Do you want to update more fields? (y/n): ";
                cin >> more_update;
                if (more_update != 'y' && more_update != 'Y') {
                    continue_update = false;
                }
            }
        }
        printTabs(4); cout << "Employee information updated successfully!" << endl;
        Enter();
    } else {
        printTabs(4); cout << "Employee not found!!!" << endl;
        Enter();
    }
}

void SystemManager::displayList() {
    Node* current = head;
    int count = 1;
    cout << "=================================================================================================================================================================" << endl;
    cout << setw(5)  << left << setfill(' ') << "|ON";
    cout << setw(11) << left << setfill(' ') << "|StaffCode";
    cout << setw(20) << left << setfill(' ') << "|Department";
    cout << setw(17) << left << setfill(' ') << "|Position";
    cout << setw(25) << left << setfill(' ') << "|Full Name";
    cout << setw(7)  << left << setfill(' ') << "|Gender";
    cout << setw(15) << left << setfill(' ') << "|Date of Birth";
    cout << setw(15) << left << setfill(' ') << "|Phone Number";
    cout << setw(25) << left << setfill(' ') << "|Email Address";
    cout << setw(20) << left << setfill(' ') << "|Salary Coeficient";
    cout << "|" << endl;
    cout << "=================================================================================================================================================================" << endl;
    while (current != nullptr) {
        cout << "|" << setw(4)  << left  << setfill(' ') << count++;
        cout << "|" << setw(10) << left  << setfill(' ') << current->staff->getStaffCode();
        cout << "|" << setw(19) << left  << setfill(' ') << current->staff->getDepartment();
        cout << "|" << setw(16) << left  << setfill(' ') << current->staff->getPosition();
        cout << "|" << setw(24) << left  << setfill(' ') << current->staff->getFullName();
        cout << "|" << setw(6)  << left  << setfill(' ') << current->staff->getGender();
        cout << "|" << setw(14) << left  << setfill(' ') << current->staff->getBirthdate() << "    ";
        cout << "|" << setw(14) << left  << setfill(' ') << current->staff->getPhoneNumber();
        cout << "|" << setw(24) << left  << setfill(' ') << current->staff->getAddressEmail();
        cout << "|" << setw(19) << right << setfill(' ') << fixed << setprecision(1) << current->staff->getSalaryCoeficient();
        cout << "|" << endl;
        current = current->next;
    }
    cout << "=================================================================================================================================================================" << endl;
}

void SystemManager::displayWorkingdaysInformation() {
    Node* current = head;
    int count = 1;
    cout << "------------------------------------------------------- Workingdays Information -------------------------------------------------------------" << endl;
    cout << setw(5)  << left << "|ON";
    cout << setw(11) << left << "|StaffCode";
    cout << setw(20) << left << "|Department";
    cout << setw(17) << left << "|Position";
    cout << setw(25) << left << "|Full Name";
    cout << setw(15) << left << "|Phone Number";
    cout << setw(12) << left << "|Working Day";
    cout << setw(20) << left << "|Review";
    cout << setw(15) << left << "|Bonus";
    cout << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (current != nullptr) {
        int daysWorked = 20 - current->staff->getDayOff();
        cout << "|" << setw(4)  << left  << setfill(' ') << count++;
        cout << "|" << setw(10) << left  << setfill(' ') << current->staff->getStaffCode();
        cout << "|" << setw(19) << left  << setfill(' ') << current->staff->getDepartment();
        cout << "|" << setw(16) << left  << setfill(' ') << current->staff->getPosition();
        cout << "|" << setw(24) << left  << setfill(' ') << current->staff->getFullName();
        cout << "|" << setw(14) << left  << setfill(' ') << current->staff->getPhoneNumber();
        cout << "|" << setw(11) << right << setfill(' ') << daysWorked;
        cout << "|" << setw(19) << right << setfill(' ') << current->staff->getReview(2);
        cout << "|" << setw(14) << right << fixed << setprecision(3) << setfill(' ') << current->staff->getBonus();
        cout << "|" << endl;
        current = current->next;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void SystemManager::displaySalaryInformation() {
    Node* current = head;
    int count = 1;
    cout << "---------------------------------------------------------- Salary Information ------------------------------------------------------------------" << endl;
    cout << setw(5)  << left << "|ON";
    cout << setw(11) << left << "|Staff Code";
    cout << setw(20) << left << "|Department";
    cout << setw(17) << left << "|Position";
    cout << setw(25) << left << "|Full Name";
    cout << setw(15) << left << "|Phone Number";
    cout << setw(15) << left << "|Salary";
    cout << setw(15) << left << "|Basic Salary";
    cout << setw(20) << left << "|Salary Coeficient";
    cout << "|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (current != nullptr) {
        cout << "|" << setw(4)  << left  << setfill(' ') << count++;
        cout << "|" << setw(10) << left  << setfill(' ') << current->staff->getStaffCode();
        cout << "|" << setw(19) << left  << setfill(' ') << current->staff->getDepartment();
        cout << "|" << setw(16) << left  << setfill(' ') << current->staff->getPosition();
        cout << "|" << setw(24) << left  << setfill(' ') << current->staff->getFullName();
        cout << "|" << setw(14) << left  << setfill(' ') << current->staff->getPhoneNumber();
        cout << "|" << setw(14) << right << setfill(' ') << fixed << setprecision(3) << current->staff->getSalary();
        cout << "|" << setw(14) << right << setfill(' ') << fixed << setprecision(3) << current->staff->getBasicSalary();
        cout << "|" << setw(19) << right << setfill(' ') << fixed << setprecision(1) << current->staff->getSalaryCoeficient();
        cout << "|" << endl;
        
        current = current->next;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
}

void SystemManager::ReadDataFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        printTabs(4); cerr << "\t\tUnable to open file " << fileName << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string on, staffCode, department, position, fullName, gender, birthDate, phoneNumber, email, salaryStr, salaryCoefficientStr, reviewStr, dayOffStr;
        auto trim = [](string &s) {
            s.erase(0, s.find_first_not_of(' ')); // Xóa dấu cách ở đầu
            s.erase(s.find_last_not_of(' ') + 1); // Xóa dấu cách ở cuối nếu cần
        };
        getline(ss, on, ',');
        trim(on);
        getline(ss, staffCode, ',');
        trim(staffCode);
        getline(ss, department, ',');
        trim(department);
        getline(ss, position, ',');
        trim(position);
        getline(ss, fullName, ',');
        trim(fullName);
        getline(ss, gender, ',');
        trim(gender);
        getline(ss, birthDate, ',');
        trim(birthDate);
        getline(ss, phoneNumber, ',');
        trim(phoneNumber);
        getline(ss, email, ',');
        trim(email);
        getline(ss, salaryStr, ',');
        trim(salaryStr);
        getline(ss, salaryCoefficientStr, ',');
        trim(salaryCoefficientStr);
        getline(ss, reviewStr, ',');
        trim(reviewStr);
        getline(ss, dayOffStr, '.');
        trim(dayOffStr);
        
        double salary = stod(salaryStr);
        float salaryCoefficient = stof(salaryCoefficientStr);
        double review = stod(reviewStr);
        int dayOff = stoi(dayOffStr);
        
        Date birthDateObj(birthDate);
        Attendance attendance(review,dayOff);
        Payroll payroll(salaryCoefficient, salary, attendance);
        Staff* staff = new Staff(fullName, gender, birthDateObj, phoneNumber, email, staffCode, position, department, payroll);
        append(staff);
    }
    file.close();
    cout << endl;
    printTabs(4); cout << "File read successfully!" << endl;
}

void SystemManager::WriteDataToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
    	cerr << "\t\tUnable to write to file " << fileName << " !!!" << endl;
        return;
    }
    file << "ON;Staff Code;Department;Position;Full Name;Gender;Date of Birth;Phone Number;Address Email;Salary;Review;Days Worked" << endl;

    Node* current = head;
    int count = 1;
    while (current) {
        Staff* staff = current->staff;
        int daysWorked = 20 - current->staff->getDayOff();
        file << count++ << ";";
        file << current->staff->getStaffCode() << ";";
        file << current->staff->getDepartment() << ";";
        file << current->staff->getPosition() << ";";
        file << current->staff->getFullName() << ";";
        file << current->staff->getGender() << ";";
        file << current->staff->getBirthdate() << ";";
        file << current->staff->getPhoneNumber() << ";";
        file << current->staff->getAddressEmail() << ";";
        file << fixed << setprecision(0) << current->staff->getSalary() << ";";
        file << fixed << setprecision(2) << current->staff->getReview(3) << ";";
        file << daysWorked << endl;

        current = current->next;
    }
    file.close();
    printTabs(4); cout << "Data written successfully to " << fileName << endl;
}

void SystemManager::UpdateData(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "\t\tUnable to write to file " << fileName << " !!!" << endl;
        return;
    }
    file << "ON, Staff Code, Department, Position, Full Name, Gender, Date of Birth, Phone Number, Email Address, Basic Salary, Salary Coefficient, Review, Day Off." << endl;
    Node* current = head;
    int count = 1;
    while (current) {
        Staff* staff = current->staff;
        file << count++;
        file << ", " << current->staff->getStaffCode();
        file << ", " << current->staff->getDepartment();
        file << ", " << current->staff->getPosition();
        file << ", " << current->staff->getFullName();
        file << ", " << current->staff->getGender();
        file << ", " << current->staff->getBirthdate();
        file << ", " << current->staff->getPhoneNumber();
        file << ", " << current->staff->getAddressEmail();
        file << ", " << fixed << setprecision(3) << current->staff->getBasicSalary();
        file << ", " << fixed << setprecision(1) << current->staff->getSalaryCoeficient();
        file << ", " << current->staff->getReview();
        file << ", " << current->staff->getDayOff();
        file << "." << endl;
        
        current = current->next;
    }
    file.close();
    printTabs(4); cout << "Updated data successfully..." << endl;
}