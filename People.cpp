//People.cpp:
#include<iostream>
#include<string>
#include"People.h"

using namespace std;

People::People(string fullname, string gender, Date birthdate, string phonenumber, string addressemail):
FullName(fullname), Gender(gender), BirthDate(birthdate), PhoneNumber(phonenumber), AddressEmail(addressemail) { }
People::~People() { }

string People::getFullName()         const { return FullName;     }
string People::getGender()           const { return Gender;       }
Date   People::getBirthdate()        const { return BirthDate;    }
string People::getPhoneNumber()      const { return PhoneNumber;  }
string People::getAddressEmail()     const { return AddressEmail; }

void People::setFullName(const string& fullname)          { FullName = fullname;         }  
void People::setGender(const string& gender)              { Gender = gender;             }
void People::setBirthDate(const Date& birthdate)          { BirthDate = birthdate;       }
void People::setPhoneNumber(const string& phonenumber)    { PhoneNumber = phonenumber;   }
void People::setAddressEmail(const string& addressemail)  { AddressEmail = addressemail; }

void People::AddInfor() {
    printTabs(4); cout << "Full Name            : "; cin.ignore(); getline(cin, FullName);
    printTabs(4); cout << "Gender               : "; getline(cin, Gender);
    printTabs(4); cout << "Date of Birth "; cin>>BirthDate;
    printTabs(4); cout << "Phone Number         : "; cin.ignore(); getline(cin, PhoneNumber);
    printTabs(4); cout << "AddressEmail         : "; getline(cin, AddressEmail);
}      

void People::DisplayInfor() const {
    printTabs(4); cout << "Full Name            : "<< FullName     << endl;
    printTabs(4); cout << "Gender               : "<< Gender       << endl; 
    printTabs(4); cout << "Date of Birth        : "<< BirthDate    << endl; 
    printTabs(4); cout << "Phone Number         : "<< PhoneNumber  << endl;
    printTabs(4); cout << "AddressEmail         : "<< AddressEmail << endl;
}
