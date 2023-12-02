#pragma once
#include <string>
#include <cmath>


//#include <iostream>
using namespace std;

class Triangle {
private:
    double sideA;
    double sideB;
    double sideC;
    void getSides(int angleNumber, double sides[3]);

public:
    Triangle(double sideA, double sideB, double angle);

    void increaseAngle(int angleNumber, double deltaAngle);
    double getAngle(int angleNumber);
    double getBisectorLength(int angleNumber);
    void getLengthOfSegmentsDividedByBisectors(int angleNumber, double result[2]);

    string toString();
};

