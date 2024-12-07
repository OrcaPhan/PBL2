// Attendance.cpp:
#include <iostream>
#include <string>
#include "Attendance.h"

using namespace std;

Attendance::Attendance(double review, int dayoff) : Review(review), DayOff(dayoff) { }
Attendance::~Attendance() {}

double Attendance::getReview() const {  return Review; }
int    Attendance::getDayOff() const {  return DayOff; }

string Attendance::getReview(int other) const {
    if (Review >= 9) return "Outstanding";
    else if (Review < 9 && Review >= 7.5) return "Good performance";
    else if (Review < 7.5 && Review >= 6) return "Satisfactory";
    else return "Unsatisfactory!";
}

void Attendance::setReview(const double& target) { Review = target; }
void Attendance::setDayOff(const int& dayoff)    { DayOff = dayoff; }

