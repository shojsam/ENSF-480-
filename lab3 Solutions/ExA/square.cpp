/*
* File Name: square.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "square.h"

Square::Square(const double x, const double y, double side_a, const char* name): Shape(name, x, y), side_a(side_a){};

Square::Square(const Square& other): Shape(other), side_a(other.side_a) {};

Square& Square::operator=(const Square& rhs){
    if(this != & rhs){
        Shape::operator=(rhs);
        side_a = rhs.side_a;
    }
    return *this;
}

double Square::area() {
    return side_a*side_a;
}

double Square::perimeter() {
    return side_a*4;
}
double const Square::get_side_a(){
    return side_a;
}
void Square::set_side_a(double length) {
    side_a = length;
}

void Square::display(){
    cout << "\nSquare Name: " << shapeName
    << "\nX-coordinate: " << origin.get_x() 
    << "\nY-coordinate: " << origin.get_y() 
    << "\nSide a: " << side_a
    << "\nArea: " << area()
    << "\nPerimeter: " << perimeter()
    << "\n" << endl;
}