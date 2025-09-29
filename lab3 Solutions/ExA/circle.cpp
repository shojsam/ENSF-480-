/*
* File Name: circle.cpp
* Assignment: Lab 3 Exercice A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "circle.h"
#include <cmath>

Circle::Circle(const double x, const double y,const double radius, const char* name)
    : Shape(name, x, y), radius(radius){};

Circle::Circle(const Circle& other): Shape(other), radius(other.radius) {};

Circle& Circle::operator=(const Circle& rhs){
    if(this != &rhs){
        Shape::operator=(rhs);
        radius = rhs.radius;
    }
    return *this;
};

double Circle::area(){
    return M_PI * radius * radius;
};

double Circle::perimeter(){
    return 2 * M_PI * radius;
};

const double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(const double radius) {
    this->radius = radius;
}

void Circle::display(){
    cout << "\nCircle Name: " << shapeName
    << "\nX-coordinate: " << origin.get_x() 
    << "\nY-coordinate: " << origin.get_y() 
    << "\nRadius: " << radius
    << "\nArea: " << area()
    << "\nPerimeter: " << perimeter()
    << "\n" << endl;
}
