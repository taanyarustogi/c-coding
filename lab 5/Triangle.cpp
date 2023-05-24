//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle(string n, float x1, float y1, float x2, float y2, float x3, float y3):Shape(n, ((x1+x2+x3)/3), ((y1+y2+y3)/3)) {
    coordx1 = x1;
    coordx2 = x2;
    coordx3 = x3;
    coordy1 = y1;
    coordy2 = y2;
    coordy3 = y3;
}

Triangle::~Triangle() {
    // Nothing to do
}

float Triangle::getx1() const {
    return coordx1;
}

float Triangle::getx2() const {
    return coordx2;
}

float Triangle::getx3() const {
    return coordx3;
}

float Triangle::gety1() const {
    return coordy1;
}

float Triangle::gety2() const {
    return coordy2;
}

float Triangle::gety3() const {
    return coordy3;
}

void Triangle::setx1(float c) {
    coordx1 = c;
}

void Triangle::setx2(float c) {
    coordx2 = c;
}

void Triangle::setx3(float c) {
    coordx3 = c;
}

void Triangle::sety1(float c) {
    coordy1 = c;
}

void Triangle::sety2(float c) {
    coordy2 = c;
}
void Triangle::sety3(float c) {
    coordy3 = c;
}

void Triangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
         << x_centre << " " << y_centre << " " << coordx1 << " " << coordy1 << " " << coordx2 << " " << coordy2 << " " << coordx3 << " " << coordy3
         << " " << computeArea()
         << endl;
}

float Triangle::computeArea() const {
    float area = abs(coordx1*(coordy2-coordy3) + coordx2*(coordy3-coordy1) + coordx3*(coordy1-coordy2))/2;
    return (area);
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}

