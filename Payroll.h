//Payroll.h:
#ifndef Payroll_h
#define Payroll_h
#include<iostream>
#include<string>
#include"Attendance.h"

using namespace std;

class Payroll {
    protected:
        float SalaryCoefficient;
        double BasicSalary;
        Attendance attendance;
    public:
        Payroll(float =0.0, double =0.00, Attendance =Attendance());
        ~Payroll();

        float  getSalryCoefficient()const;
        double getBasicSalry()const;
        double getReview() const;
        string getReview(int) const;
        int    getDayOff() const;

        void setSalryCoefficient(const float& );
        void setBasicSalry(const double& );
        void setReview(const double&) ;
        void setDayOff(const int&) ; 
        
        double GetBonus() const;
        double GetDecuction() const;
        double calculateSalary() const;
};

#endif