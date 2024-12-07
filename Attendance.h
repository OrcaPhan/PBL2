// Attendance.h:
#ifndef Attendance_h
#define Attendance_h
#include<iostream>
#include<string>

using namespace std;

class Attendance {
    protected:
        double Review;
        int DayOff;
    public:
        Attendance(double =0.0, int =0);
        ~Attendance();
        
        double getReview() const;
        string getReview(int) const;
        int    getDayOff() const;

        void setReview(const double& );
        void setDayOff(const int& );
};
#endif
