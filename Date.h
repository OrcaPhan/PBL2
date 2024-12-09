//Date.h:
#ifndef Date_h
#define Date_h
#include<iostream>
#include<string>

using namespace std;

class Date {
    protected:
        int Day, Month, Year;
    public:
        Date(int = 1, int = 1, int = 2000);
        Date(const string&);
        ~Date();
        
        friend istream &operator>>(istream&, Date&);
        friend ostream &operator<<(ostream&, const Date&);
};

bool checked(int, int, int);
bool checkleap(int);

void printTabs(int);
void Enter();
int  choicetrue();

#endif