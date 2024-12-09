#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include"Date.h"

using namespace std;
    
Date::Date(int Day, int Month, int Year) : Day(Day), Month(Month), Year(Year) { }

Date::Date(const string &DateString) {
    stringstream ss(DateString);
    char dash;
    if (!(ss >> Day >> dash >> Month >> dash >> Year) || !checked(Day, Month, Year)) {
        if (dash != '-' || ss.fail()) {
            cout << "\t\tError: Invalid date format '" << DateString << "'. Using default date 01-01-2000." << endl;
        } else {
            cout << "\t\tError: Invalid date values for '" << DateString << "'. Using default date 01-01-2000." << endl;
        }
        Day = 1; Month = 1; Year = 2000;
    }
}

Date::~Date() { }

istream &operator>>(istream &in, Date &dt) {
    do {
        cout << "(dd/mm/yyyy): ";
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

ostream &operator<<(ostream &out, const Date &dt) {
    out << setw(2) << right << setfill('0') << dt.Day << "/"  << setw(2) << right << setfill('0') << dt.Month << "/" << dt.Year;
    return out;
}

bool checked(int Day, int Month, int Year) {
    if (Day >= 1 && Day <= 31 && Month >= 1 && Month <= 12) {
        if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
            return Day <= 31;
        else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
            	return Day <= 30;
        	else if (checkleap(Year))
            		return Day <= 29;
        		else
            		return Day <= 28;
    }
    return false;
}

bool checkleap(int Year) {
    if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
        return true;
    else
        return false;
}

void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; ++i) {
        cout << "\t";
    }
}

void Enter() {
	              cout << endl;
    printTabs(4); cout << "Press Enter to continue...";
                  cin.ignore();
                  cin.get();
}

int choicetrue() {
    string choice;
    cin >> choice;
    if (choice.length() == 1) {
        return choice[0] - 48;
    } else {
    	printTabs(4); cout << "Invalid choice!" << endl;
    	Enter();
    	return -1;
    }
}