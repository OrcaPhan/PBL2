//Staff.cpp:
#include<iostream>
#include<string>
#include <iomanip> 
#include"Date.h"
#include"People.h"
#include"Payroll.h"
#include"Attendance.h"
#include"Staff.h"

using namespace std;

Staff::Staff(string fullname, string gender, Date birthdate, string phonenumber, string addressemail, string staffcode, string position, string department, Payroll payroll):
People(fullname, gender, birthdate, phonenumber, addressemail), StaffCode(staffcode), Position(position), Department(department), Salary(payroll) { }

Staff::~Staff() { }

string  Staff::getStaffCode()             const { return StaffCode;                    }
string  Staff::getPosition()              const { return Position;                     }
string  Staff::getDepartment()            const { return Department;                   }
float   Staff::getSalaryCoeficient()      const { return Salary.getSalryCoefficient(); }
double  Staff::getBasicSalary()           const { return Salary.getBasicSalry();       }
double  Staff::getReview()                const { return Salary.getReview();           }
string  Staff::getReview(int)             const { return Salary.getReview(2);          }
int     Staff::getDayOff()                const { return Salary.getDayOff();           }
double  Staff::getBonus()                 const { return Salary.GetBonus();            }
double  Staff::getSalary()                const { return Salary.calculateSalary();     }

void Staff::setStaffCode(const string& staffcode)   { StaffCode = staffcode;           }
void Staff::setPosition(const string& position)     { Position = position;             }
void Staff::setDepartment(const string& department) { Department = department;         }
void Staff::setReview(const double& review)         { Salary.setReview(review);        }
void Staff::setDayOff(const int& dayoff)            { Salary.setDayOff(dayoff);        }
void Staff::setSalaryCoefficient(const float& SCt)  { Salary.setSalryCoefficient(SCt); }
void Staff::setBasicSalary(const double& BSy)       { Salary.setBasicSalry(BSy);       }

void Staff::AddInfor() {
    float salaryCoefficient;
    int   dayOff;
    double review, basicSalary;
    printTabs(4); cout << "Staff Code           : "; cin.get() ; getline(cin, StaffCode);
    People::AddInfor();
    printTabs(4); cout << "Position             : "; getline(cin, Position);
    printTabs(4); cout << "Department           : "; getline(cin, Department);
    printTabs(4); cout << "Salary Coefficient   : "; cin >> salaryCoefficient; Salary.setSalryCoefficient(salaryCoefficient);
    printTabs(4); cout << "Basic Salary         : "; cin >> basicSalary; Salary.setBasicSalry(basicSalary);
    printTabs(4); cout << "Day Off              : "; cin >> dayOff; Salary.setDayOff(dayOff);
    printTabs(4); cout << "Review (Enter on a 10-point scale ): "; cin >> review; Salary.setReview(review);
                                                
}

void Staff::DisplayInfor() const {
    cout << endl;
    printTabs(4); cout << "Staff Code           : " << StaffCode << endl;
    People::DisplayInfor();
    printTabs(4); cout << "Position             : " << Position << endl;
    printTabs(4); cout << "Department           : " << Department << endl;
    printTabs(4); cout << "Salary               : " << fixed << setprecision(3) << getSalary() << endl;
    printTabs(4); cout << "Salary Coefficient   : " << fixed << setprecision(1) << Salary.getSalryCoefficient() << endl;
    printTabs(4); cout << "Basic Salary         : " << fixed << setprecision(3) << Salary.getBasicSalry() << endl;
    printTabs(4); cout << "Day Off              : " << Salary.getDayOff() << endl;
    printTabs(4); cout << "Review               : " << fixed << setprecision(1) << Salary.getReview() << " (" << Salary.getReview(2) << ")" << endl;
}