//People.h:
#ifndef People_h
#define People_h
#include<iostream>
#include<string>
#include"Date.h"

using namespace std;

class People {
    protected:
        string FullName, Gender, PhoneNumber, AddressEmail;
        Date BirthDate;
    public:
        People(string ="NULL", string ="NULL", Date =Date(), string ="NULL", string ="NULL");
        ~People();

        string getFullName() const;
        string getGender() const;
        Date   getBirthdate() const;
        string getPhoneNumber() const;
        string getAddressEmail() const;

        void setFullName(const string&);
        void setGender(const string&);
        void setBirthDate(const Date&);
        void setPhoneNumber(const string&);
        void setAddressEmail(const string&);

        virtual void AddInfor();
        virtual void DisplayInfor() const;
        virtual double getSalary()  const=0;
};

#endif