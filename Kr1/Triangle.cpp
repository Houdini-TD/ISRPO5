#define _USE_MATH_DEFINES 
#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <array>

Triangle::Triangle(double sideA, double sideB, double angle) {
    this->sideA = sideA;
    this->sideB = sideB;
    double radianAngle = angle * M_PI / 180.0;
    this->sideC = sqrt(pow(this->sideA, 2) + pow(this->sideB, 2) - 2 * this->sideB * this->sideA * cos(radianAngle));
}

double Triangle::getAngle(int angleNumber) {
    double p = -1;
    switch (angleNumber) {
    case 0:
        p = (sideB * sideB - sideC * sideC + sideA * sideA) / (2.0 * sideA * sideB);
        return acos(p - static_cast<int>(p));
    case 1:
        p = (sideB * sideB + sideC * sideC - sideA * sideA) / (2.0 * sideC * sideB);
        return acos(p - static_cast<int>(p));
    case 2:
        p = (-sideB * sideB + sideC * sideC + sideA * sideA) / (2.0 * sideA * sideC);
        return acos(p - static_cast<int>(p));
    default:
        return p;
    }
}

void Triangle::increaseAngle(int angleNumber, double deltaAngle) {
    double sides[3];
    getSides(angleNumber, sides);
    double currentAngle = getAngle(angleNumber);
    double newAngle = currentAngle + deltaAngle;
    int newSide = sqrt(pow(sides[1], 2) + pow(sides[2], 2) - 2 * sides[1] * sides[2] * cos(newAngle));
    if (newSide <= 0) {
        std::cout << "Invalid angle increase. New side length is non-positive." << std::endl;
        return;
    }
    switch (angleNumber) {
    case 0:
        this->sideC = newSide;
        break;
    case 1:
        this->sideA = newSide;
        break;
    case 2:
        this->sideB = newSide;
        break;
    }
}

double Triangle::getBisectorLength(int angleNumber) {
    double sides[3];
    double angle = getAngle(angleNumber);
    getSides(angleNumber, sides);
    return 2 * sides[1] * sides[2] * cos(angle / 2.0) / (sides[1] + sides[2]);
}

void Triangle::getSides(int angleNumber, double sides[3]) {
    switch (angleNumber) {
    case 0:
        sides[0] = this->sideC;
        sides[1] = this->sideA;
        sides[2] = this->sideB;
        break;
    case 1:
        sides[0] = this->sideA;
        sides[1] = this->sideB;
        sides[2] = this->sideC;
        break;
    case 2:
        sides[0] = this->sideB;
        sides[1] = this->sideC;
        sides[2] = this->sideA;
        break;
    }
}

void Triangle::getLengthOfSegmentsDividedByBisectors(int angleNumber, double result[2]) {
    double sides[3];
    getSides(angleNumber, sides);
    result[0] = (sides[2] * sides[0]) / (sides[1] + sides[2]);
    result[1] = (sides[1] * sides[0]) / (sides[1] + sides[2]);
}

std::string Triangle::toString() {
    return "Стороны треугольника: " + std::to_string(sideA) + " см, " + std::to_string(sideB) + " см, " + std::to_string(sideC) + " см" +
        "\nУглы треугольника: " +
        "alpha=" + std::to_string(getAngle(0) * 180 / M_PI) + "°, " +
        "beta=" + std::to_string(getAngle(1) * 180 / M_PI) + "°, " +
        "gamma=" + std::to_string(getAngle(2) * 180 / M_PI) + "°";
}






