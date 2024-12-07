#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include"Date.h"

using namespace std;
    
Date::Date(int Day, int Month, int Year) : Day(Day), Month(Month), Year(Year) { }
Date::~Date() { }

Date::Date(const string &DateString) {
    stringstream ss(DateString);
    char dash;
    if (!(ss >> Day >> dash >> Month >> dash >> Year) || !checked(Day, Month, Year)) {
        if (dash != '-' || ss.fail()) {
            cout << "\t\tError: Invalid date format '" << DateString << "'. Using default date 01-01-1000." << endl;
        } else {
            cout << "\t\tError: Invalid date values for '" << DateString << "'. Using default date 01-01-1000." << endl;
        }
        Day = 1; Month = 1; Year = 1000;
    }
}

istream &operator>>(istream &in, Date &dt) {
    do {
        cout << "(dd-mm-yyyy): ";
        string datestring;
        char dash;
        in >> datestring;
        stringstream ss(datestring);
        ss >> dt.Day >> dash >> dt.Month >> dash >> dt.Year;
        if (!checked(dt.Day, dt.Month, dt.Year))
            cout << "\t\tError date!!!" << endl;
    } while (!checked(dt.Day, dt.Month, dt.Year));
    return in;
}

ostream &operator<<(ostream &out, const Date &t) {
    out << setw(2) << setfill('0') << t.Day << "-"  << setw(2) << setfill('0') << t.Month << "-" << t.Year;
    return out;
}
