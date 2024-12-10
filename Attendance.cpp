//Attendance.cpp:
#include <iostream>
#include <string>
#include "Attendance.h"

using namespace std;

Attendance::Attendance(double review, int dayoff) : Review(review), DayOff(dayoff) { }

Attendance::~Attendance() {}

double Attendance::getReview() const {  return Review; }

string Attendance::getReview(int) const {
    if (Review >= 9.5) return "Outstanding";
    else if (Review >= 8.5 && Review < 9.5) return "Good performance";
        else if (Review >= 7 && Review < 8.5) return "Satisfactory";
            else return "Unsatisfactory!";
}

int    Attendance::getDayOff() const {  return DayOff; }

void Attendance::setReview(const double& target) { Review = (double)target; }

void Attendance::setDayOff(const int& dayoff)    { DayOff = dayoff; }