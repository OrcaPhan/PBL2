#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>

#include"Date.h"
#include"Attendance.h"
#include"Payroll.h"
#include"Staff.h"
#include"People.h"
#include"SystemManager.h"
using namespace std;
/* 
g++ main.cpp Date.h Date.cpp Attendance.h Attendance.cpp Payroll.h Payroll.cpp People.h People.cpp Staff.h Staff.cpp SystemManager.h SystemManager.cpp -o  test.exe 
*/
void Readfile(SystemManager &,string &);
void Writefile(SystemManager &);
void Menu();
void searchEmployee(SystemManager &);
void displayInformation(SystemManager &);
static bool fileLoaded = false;

int main() {
    Menu();
    return 0;
}

void Readfile(SystemManager &other, string &filename){
    printTabs(4);  cout << "Enter file name: ";
                  cin >> filename;
                   other.ReadDataFromFile(filename+".txt");
    fileLoaded = true;
}

void Writefile(SystemManager &other){
    string filename;    
    printTabs(4);  cout << "Enter file name: ";
                   cin >> filename;
                   other.WriteDataToFile(filename+".txt");
}

void Menu() {
    int choice;
    string staffCode;
    string filename;
    SystemManager systemManager;
    Staff* newStaff;
    do {
        system("cls");
        printTabs(4); printStr('=', 29, false); cout<< " Menu "; printStr('=', 29, true);
                      cout <<endl;
        printTabs(4); cout << "     1. Read employee list from file                             " << endl;
        printTabs(4); cout << "     2. Save employee list to file                               " << endl;
        printTabs(4); cout << "     3. Search employee                                          " << endl;
        printTabs(4); cout << "     4. Display information                                      " << endl;
        printTabs(4); cout << "     5. Add employee                                             " << endl;
        printTabs(4); cout << "     6. Update information                                       " << endl;
        printTabs(4); cout << "     7. Delete employee                                          " << endl;
        printTabs(4); cout << "     0. Exit                                                     " << endl;
                      cout <<endl;
        printTabs(4); printStr('=', 64, true);
        printTabs(4); cout << "Enter your choice: ";
        choice= choicetrue();
        if (choice > 1 && choice < 8) {
            if (!fileLoaded) {
                printTabs(4); cout << "File not read. Please load a file to proceed." << endl;
                Enter();
                choice = -1;// de khong phai nhap Enter 2 lan
            } 
        }
        switch (choice) {
            case 1: 
                Readfile(systemManager,filename);
                Enter();
                break;
            case 2:
                Writefile(systemManager);
                Enter();         
                break;
            case 3:
                searchEmployee(systemManager);
                Enter();
                break;
            case 4: 
                displayInformation(systemManager);
                break;
            case 5: {
                Staff* newStaff = new Staff();
                newStaff->AddInfor(); 
                systemManager.append(newStaff);
                printTabs(4); cout << "Employee added successfully!" << endl;
                Enter();
                break;
                }
            case 6: 
                printTabs(4); cout << "Enter staff code to edit: ";
                cin >> staffCode;
                newStaff = systemManager.findByStaffCode(staffCode);
                if (newStaff) {
                    systemManager.updateInfor(staffCode, *newStaff);
                    printTabs(4); cout << "Employee information updated successfully!" << endl;
                } else {
                    printTabs(4); cout << "Staff not found!" << endl;
                }       
                Enter();                
                break;
            case 7: 
                printTabs(4); cout << "Enter staff code to delete: ";
                cin >> staffCode;
                systemManager.remove(staffCode);                
                Enter();
                break;
            case -1: 
                break;
            case 0:
                cout << endl;
                systemManager.UpdateData(filename+".txt");
                printTabs(5); cout << "Exiting program!";
                break;
            default:
                printTabs(4); cout << "Invalid choice!" << endl;
                Enter();
                break;
        }
    } while (choice != 0);
}

void searchEmployee(SystemManager &other) {
    int choice3;
    string staffCode, staffName;
    do {
        system("cls");
        printTabs(4); printStr('=', 15, false); cout<< " Search Employee "; printStr('=', 15, true);
                      cout <<endl;
        printTabs(4); cout << "     1. Search by staff code                     " << endl;
        printTabs(4); cout << "     2. Search by name                           " << endl;
        printTabs(4); cout << "     0. Back                                     " << endl;
                      cout <<endl;
        printTabs(4); printStr('=', 49, true);
        printTabs(4); cout << "Enter your choice: ";
        choice3= choicetrue();
        switch (choice3) {
            case 1: 
                printTabs(4); cout << "Enter staff code: ";
                cin >> staffCode;
                other.displayByStaffCode(staffCode);
                Enter();
                break;            
            case 2:
                printTabs(4); cout << "Enter Full name: ";
                cin.ignore();
                getline(cin, staffName); 
                other.displayByFullName(staffName);
                Enter();
                break;
            case -1: case 0:
                break;
            default:
                printTabs(4); cout << "Invalid choice!" << endl;
                Enter();
                break;
        }
    } while (choice3 != 0);
}

void displayInformation(SystemManager &other) {
    int choice4;
    do {
        system("cls");
        printTabs(4); printStr('=', 15, false); cout<< " Display Information "; printStr('=', 15, true);
                      cout <<endl;
        printTabs(4); cout << "     1. Display employee information             " << endl;
        printTabs(4); cout << "     2. Display salary information               " << endl;
        printTabs(4); cout << "     3. Display work information                 " << endl;
        printTabs(4); cout << "     0. Back                                     " << endl;
                      cout <<endl;
        printTabs(4); printStr('=', 51, true);
        printTabs(4); cout << "Enter your choice: ";
        choice4= choicetrue();
        switch (choice4) {
            case 1: 
                other.displayList(); 
                Enter();
                break;
            case 2:
                other.displaySalaryInformation();
                Enter();
                break;
            case 3:
                other.displayWorkingdaysInformation();
                Enter();
                break;
            case -1: case 0:
                break;
            default:
                printTabs(4); cout << "Invalid choice!" << endl;
                Enter();
                break;
        }
    } while (choice4 != 0);
}
