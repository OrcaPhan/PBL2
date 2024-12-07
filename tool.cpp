#include<iostream>
#include<string>
#include"tool.h"
using namespace std;

void printTabs(int count) {
    for (int i = 0; i < count; ++i) {
        cout << "\t";
    }
}

void printStr(char cr, int count, bool endline) {
    for (int i = 0; i < count; ++i) {
        cout <<cr;
    }
    if(endline)
    cout<<endl;
}

void Enter(){
                  cout << endl;
    printTabs(4); cout << " Press Enter to continue...";
                  cin.ignore();
                  cin.get();
}

int choicetrue(){
    string choice;
    cin>> choice;
    if(choice.length()==1){
        return choice[0]-48;
        }
    else{
    printTabs(4); cout << "Invalid choice!" << endl;
    Enter();
        return -1;
    }
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
