//SystemManager.h:
#ifndef SystemManager_h
#define SystemManager_h
#include<iostream>
#include<string>
#include <vector>
#include"People.h"
#include"Staff.h"

using namespace std;

class SystemManager {
    private:
        class Node {
            public:
                Staff* staff;
                Node* next;
                Node* prev;

                Node(Staff *sta) : staff(sta), next(nullptr), prev(nullptr) {}
                ~Node() {}
        };
        Node* head;
        Node* tail;
    public:
        SystemManager();
        SystemManager(const SystemManager&);
        ~SystemManager();

        void append(Staff*);
        void remove(string);

        Staff* findByStaffCode(const string&);       // Trả về con trỏ Staff
        void displayByStaffCode(const string&);      // Hiển thị thông tin nhân viên
        
        vector<Staff*> findByFullName(const string& );
        void displayByFullName(const string& );

        void updateInfor(string, const Staff&);

        void displayList();
                
        void displaySalaryInformation();
        void displayWorkingdaysInformation();

        void ReadDataFromFile(const string&);
        void WriteDataToFile(const string&);
        void UpdateData(const string&);
};
#endif
