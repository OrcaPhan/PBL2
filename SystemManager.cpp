//SystemManager.cpp:
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include"People.h"
#include"Staff.h"
#include"Payroll.h"
#include"Attendance.h"
#include"SystemManager.h"
#include <iomanip> 

using namespace std;

SystemManager::SystemManager() : head(nullptr), tail(nullptr) {}
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
            printTabs(4); cout << "Staff removed successfully!" << endl;
            return;
        }
        current = current->next;
    }
    printTabs(4); cout << "Staff not found!" << endl;
}

void SystemManager::displayList() {
    Node* current = head;
    int count=1;
        printStr('=', 161, true);

    cout <<setw(5) <<left<<setfill(' ')<<"|Stt";
    cout <<setw(11)<<left<<setfill(' ')<<"|StaffCode";
    cout <<setw(21)<<left<<setfill(' ')<<"|Department";
    cout <<setw(19)<<left<<setfill(' ')<<"|position";
    cout <<setw(25)<<left<<setfill(' ')<<"|Full Name";
    cout <<setw(5) <<left<<setfill(' ')<<"|Sex";
    cout <<setw(15)<<left<<setfill(' ')<<"|Date of Birth";
    cout <<setw(14)<<left<<setfill(' ')<<"|Phone Number";
    cout <<setw(26)<<left<<setfill(' ')<<"|Email";
    cout <<setw(19)<<left<<setfill(' ')<<"|Salary Coeficient";
    cout <<"|"<<endl;
        printStr('=', 161, true);

    while (current != nullptr) {
        cout <<"|"<<setw(4) <<left <<setfill(' ')<<count++;
        cout <<"|"<<setw(10)<<left <<setfill(' ')<<current->staff->getStaffCode();
        cout <<"|"<<setw(20)<<left <<setfill(' ')<<current->staff->getDepartment();
        cout <<"|"<<setw(18)<<left <<setfill(' ')<<current->staff->getPosition();
        cout <<"|"<<setw(24)<<left <<setfill(' ')<<current->staff->getFullName();
        cout <<"|"<<setw(4) <<left <<setfill(' ')<<current->staff->getGender();
        cout <<"|"<<setw(13)<<left <<setfill(' ')<<current->staff->getBirthdate()<<"    ";
        cout <<"|"<<setw(13)<<left <<setfill(' ')<<current->staff->getPhoneNumber();
        cout <<"|"<<setw(25)<<left <<setfill(' ')<<current->staff->getAddressEmail();
        cout <<"|"<<setw(18)<<right<<setfill(' ')<<fixed<<setprecision(2)<<current->staff->getSalaryCoeficient();
        cout <<"|"<<endl;
        current = current->next;
    }
    printStr('=', 161, true);
}

void SystemManager::updateInfor(string staffcode, const Staff& updatestaff) {
    Staff* staff = findByStaffCode(staffcode);
    if (staff != nullptr) {
        int update_choice;
        bool continue_update = true;
        while (continue_update) {
            system("cls");
            printTabs(4); cout<<"The information the employee found is: "<<endl;
            staff->DisplayInfor();
                          cout<<endl;
            printTabs(4); cout << "Select field to update:" << endl;
            printTabs(4); cout << "1 . Full Name" << endl;
            printTabs(4); cout << "2 . Gender" << endl;
            printTabs(4); cout << "3 . Date of Birth" << endl;
            printTabs(4); cout << "4 . Phone Number" << endl;
            printTabs(4); cout << "5 . Addressemail" << endl;
            printTabs(4); cout << "6 . Position" << endl;
            printTabs(4); cout << "7 . Department" << endl;
            printTabs(4); cout << "8 . Day Off" << endl;
            printTabs(4); cout << "9 . Review" << endl;
            printTabs(4); cout << "10. Salary Coefficient" << endl;
            printTabs(4); cout << "11. Basic Salary " << endl;
            printTabs(4); cout << "0 . Exit Update" << endl;
            printTabs(4); cout << "Enter choice: ";
            // update_choice= choicetrue();
            cin>>update_choice;
            string fullName, gender, birthDate, phoneNumber, addressemail, position, department;
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
                    printTabs(4); cout << "New AddressEmail: ";
                    cin.ignore();
                    getline(cin, addressemail);
                    staff->setAddressEmail(addressemail);
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
                case -1: case 0:
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
        printTabs(4); cout << "Update successful..." << endl;
        Enter();
    } else {
        printTabs(4); cout << "Staff not found!!!" << endl;
        Enter();
    }
}

void SystemManager::ReadDataFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "\t\tUnable to open file " << fileName << endl;
        return;
    }
    string line;
    // Skip header lines
    getline(file, line); // Giả sử chỉ có một dòng tiêu đề
    while (getline(file, line)) {
        stringstream ss(line);
        string stt, staffCode, department, position, fullName, sex, birthDate, phoneNumber, email, salaryStr, salaryCoefficientStr, reviewStr, dayOffStr;
        auto trim = [](string &s) {
            s.erase(0, s.find_first_not_of(' ')); // Xóa dấu cách ở đầu
            s.erase(s.find_last_not_of(' ') + 1); // Xóa dấu cách ở cuối nếu cần
        };
        getline(ss, stt, ',');
        trim(stt);
        getline(ss, staffCode, ',');
        trim(staffCode);
        getline(ss, department, ',');
        trim(department);
        getline(ss, position, ',');
        trim(position);
        getline(ss, fullName, ',');
        trim(fullName);
        getline(ss, sex, ',');
        trim(sex);
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
        Staff* staff = new Staff(fullName, sex, birthDateObj, phoneNumber, email, staffCode, position, department, payroll);
        append(staff);
    }
    file.close();
    cout<<endl;
    printTabs(4); cout << "File read successfully!" << endl;
}

void SystemManager::WriteDataToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "\t\tUnable to write to file " << fileName << endl;
        return;
    }
    file<<"=========================================================================================================================================================================" << endl;
    file <<setw(5) <<left<<"|Stt";
    file <<setw(11)<<left<<"|StaffCode";
    file <<setw(12)<<left<<"|Department";
    file <<setw(10)<<left<<"|position";
    file <<setw(25)<<left<<"|FullName";
    file <<setw(5) <<left<<"|Sex";
    file <<setw(9) <<left<<"|Date of Birth";
    file <<setw(14)<<left<<"|Phone Number";
    file <<setw(25)<<left<<"|Email";
    file <<setw(17)<<left<<"|Salary";
    file <<setw(20)<<left<<"|Review";
    file <<setw(10)<<left<<"|DaysWork";
    file <<"|"<<endl;
    file<<"=========================================================================================================================================================================" << endl;

    Node* current = head;
    int count = 1;
    while (current) {
        Staff* staff = current->staff;
        int daysWorked = 30 - current->staff->getDayOff();
        file <<"|"<<setw(4) <<left <<setfill(' ')<<count++;
        file <<"|"<<setw(10)<<left <<setfill(' ')<<current->staff->getStaffCode();
        file <<"|"<<setw(11)<<left <<setfill(' ')<<current->staff->getDepartment();
        file <<"|"<<setw(9) <<left <<setfill(' ')<<current->staff->getPosition();
        file <<"|"<<setw(24)<<left <<setfill(' ')<<current->staff->getFullName();
        file <<"|"<<setw(4) <<left <<setfill(' ')<<current->staff->getGender();
        file <<"|"<<setw(17)<<left <<setfill(' ')<<current->staff->getBirthdate()<<"   ";
        file <<"|"<<setw(13)<<left <<setfill(' ')<<current->staff->getPhoneNumber();
        file <<"|"<<setw(24)<<left <<setfill(' ')<<current->staff->getAddressEmail();
        file <<"|"<<setw(16)<<right<<setfill(' ')<<fixed<<setprecision(3)<<current->staff->getSalary();
        file <<"|"<<setw(19)<<right<<setfill(' ')<<fixed<<setprecision(2)<<current->staff->getReview(3);
        file <<"|"<<setw(9) <<right<<setfill(' ')<<daysWorked;
        file <<"|"<<endl;
       
        current = current->next;
    }
    file<<"=========================================================================================================================================================================" << endl;
    file.close();
    printTabs(4); cout << "Data written successfully to " << fileName << endl;
}

void SystemManager::UpdateData(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "\t\tUnable to write to file " << fileName << endl;
        return;
    }
    file <<"Stt, Staff Code, Department, Position, Full Name, Sex, Date of Birth, Phone Number, Email, Basic Salary, Salary Coefficient, Review, Dayoff."<<endl;
    Node* current = head;
    int count = 1;
    while (current) {
        Staff* staff = current->staff;
        file <<count++;
        file <<", "<<current->staff->getStaffCode();
        file <<", "<<current->staff->getDepartment();
        file <<", "<<current->staff->getPosition();
        file <<", "<<current->staff->getFullName();
        file <<", "<<current->staff->getGender();
        file <<", "<<current->staff->getBirthdate();
        file <<", "<<current->staff->getPhoneNumber();
        file <<", "<<current->staff->getAddressEmail();
        file <<", "<<fixed<<setprecision(0)<<current->staff->getBasicSalary();
        file <<", "<<fixed<<setprecision(1)<<current->staff->getSalaryCoeficient();
        file <<", "<<current->staff->getReview();
        file <<", "<<current->staff->getDayOff();
        file <<"."<<endl;
        current = current->next;
    }
    file.close();
    printTabs(4); cout << " UpdateData successfully !" << endl;
}

void SystemManager::displayWorkingdaysInformation() {
    Node* current = head;
    int count=0;
    printStr('-', 52, false); cout<< " Workingdays Information "; printStr('-', 53, true);
    cout <<setw(5) <<left<<"|Stt";
    cout <<setw(11)<<left<<"|StaffCode";
    cout <<setw(12)<<left<<"|Department";
    cout <<setw(10)<<left<<"|position";
    cout <<setw(25)<<left<<"|FullName";
    cout <<setw(14)<<left<<"|Phone Number";
    cout <<setw(16)<<left<<"|Working Day";
    cout <<setw(20)<<left<<"|Review";
    cout <<setw(16)<<left<<"|Bonus";
    cout <<"|"<<endl;
    printStr('-', 130, true);    
    while (current != nullptr) {
        int daysWorked = 30 - current->staff->getDayOff();
        cout <<"|"<<setw(4) <<left <<setfill(' ')<<count++;
        cout <<"|"<<setw(10)<<left <<setfill(' ')<<current->staff->getStaffCode();
        cout <<"|"<<setw(11)<<left <<setfill(' ')<<current->staff->getDepartment();
        cout <<"|"<<setw(9) <<left <<setfill(' ')<<current->staff->getPosition();
        cout <<"|"<<setw(24)<<left <<setfill(' ')<<current->staff->getFullName();
        cout <<"|"<<setw(13)<<left <<setfill(' ')<<current->staff->getPhoneNumber();
        cout <<"|"<<setw(15)<<right<<setfill(' ')<<daysWorked;
        cout <<"|"<<setw(19)<<right<<setfill(' ')<<current->staff->getReview(2);
        cout <<"|"<<setw(15) <<right<<fixed<<setprecision(2)<<setfill(' ')<<current->staff->getBonus();
        cout <<"|"<<endl;
        current = current->next;
    }
    printStr('-', 130, true);        
}

void SystemManager::displaySalaryInformation() {
    Node* current = head;
    int count=0;
    printStr('-', 55, false); cout<< " Salary Information "; printStr('-', 56, true);
    cout <<setw(5) <<left<<"|Stt";
    cout <<setw(11)<<left<<"|StaffCode";
    cout <<setw(12)<<left<<"|Department";
    cout <<setw(10)<<left<<"|position";
    cout <<setw(25)<<left<<"|FullName";
    cout <<setw(14)<<left<<"|Phone Number";
    cout <<setw(17)<<left<<"|Salary";
    cout <<setw(17)<<left<<"|Basic Salary";
    cout <<setw(19)<<left<<"|Salary Coeficient";
    cout <<"|"<<endl;
    printStr('-', 131, true);
    while (current != nullptr) {
        cout <<"|"<<setw(4) <<left <<setfill(' ')<<count++;
        cout <<"|"<<setw(10)<<left <<setfill(' ')<<current->staff->getStaffCode();
        cout <<"|"<<setw(11)<<left <<setfill(' ')<<current->staff->getDepartment();
        cout <<"|"<<setw(9) <<left <<setfill(' ')<<current->staff->getPosition();
        cout <<"|"<<setw(24)<<left <<setfill(' ')<<current->staff->getFullName();
        cout <<"|"<<setw(13)<<left <<setfill(' ')<<current->staff->getPhoneNumber();
        cout <<"|"<<setw(16)<<right<<setfill(' ')<<fixed<<setprecision(3)<<current->staff->getSalary();
        cout <<"|"<<setw(16)<<right<<setfill(' ')<<fixed<<setprecision(3)<<current->staff->getBasicSalary();
        cout <<"|"<<setw(18)<<right<<setfill(' ')<<fixed<<setprecision(2)<<current->staff->getSalaryCoeficient();
        cout <<"|"<<endl;
        current = current->next;
    }
    printStr('-', 131, true);
}
    