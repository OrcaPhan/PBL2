//Date.h:
#ifndef Date_h
#define Date_h
#include<iostream>
#include<string>
#include"tool.h"

using namespace std;

class Date {
    protected:
        int Day, Month, Year;
    public:
        Date(int = 1, int = 1, int = 1000);
        Date(const string&);
        ~Date();
        friend istream &operator>>(istream&, Date&);
        friend ostream &operator<<(ostream&, const Date&);
};
#endif
