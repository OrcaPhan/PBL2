//Payroll.cpp:
#include<iostream>
#include<string>
#include"Payroll.h"

using namespace std;

Payroll::Payroll(float salarycoefficient, double basicsalary, Attendance attend): SalaryCoefficient(salarycoefficient), BasicSalary(basicsalary), attendance(attend) { }
Payroll::~Payroll(){}

float  Payroll::getSalryCoefficient()const {        return SalaryCoefficient;           }
double Payroll::getBasicSalry()const       {        return BasicSalary;                 }
double Payroll::getReview() const          {        return attendance.getReview();      }
string Payroll::getReview(int other) const {        return attendance.getReview(2);     }
int    Payroll::getDayOff() const          {        return attendance.getDayOff();      }
double Payroll::GetBonus() const           {        return getReview()*0.1*BasicSalary; }

double Payroll::calculateSalary() const {
        return (double)SalaryCoefficient * BasicSalary/30.0*(30-attendance.getDayOff())+(double)Payroll::GetBonus()-(double)Payroll::GetDecuction();
}

double Payroll::GetDecuction() const {
    if(getDayOff() == 0) return 0;
    if(getDayOff() < 5)
        return getDayOff()*0.1*BasicSalary;
    else
        return getDayOff()*0.3*BasicSalary;
}

void  Payroll::setSalryCoefficient(const float & salarycoeficient){
        SalaryCoefficient=salarycoeficient;
}
void  Payroll::setBasicSalry(const double & basicsalary){
        BasicSalary=basicsalary;
}
void Payroll::setReview(const double& review) {
        attendance.setReview(review);
}
void Payroll::setDayOff(const int& dayoff) {
        attendance.setDayOff(dayoff);
}

