//Staff.h:
#ifndef Staff_h
#define Staff_h
#include<iostream>
#include<string>
#include"People.h"
#include"Date.h"
#include"Payroll.h"

using namespace std;
class Payroll;
class Staff: public People {
    protected:
        string StaffCode;
        string Position;
        string Department;
        Payroll Salary;
    public:
        Staff(string ="NULL", string ="NULL", Date =Date(), string ="NULL", string ="NULL", string ="NULL", string ="NULL", string ="NULL", Payroll =Payroll());
        ~Staff();

        string  getStaffCode()         const;
        string  getPosition()          const;
        string  getDepartment()        const;
        float   getSalaryCoeficient()  const;
        double  getBasicSalary()       const;
        double  getReview()            const;
        string  getReview(int)         const;
        int     getDayOff()            const;
        Payroll getPayroll()           const;
        double  getBonus()             const;
        double  getDecuction()         const;
        double  getSalary()            const;

        void    setStaffCode(const string&);
        void    setPosition(const string&);
        void    setDepartment(const string&);
        void    setReview(const double&);
        void    setDayOff(const int&);
        void    setSalaryCoefficient(const float&);
        void    setBasicSalary(const double&);

        void    AddInfor();
        void    DisplayInfor() const;
};

#endif