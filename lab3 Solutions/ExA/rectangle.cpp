/*
* File Name: rectangle.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "rectangle.h"

Rectangle::Rectangle(const double x, const double y, double side_a, double side_b, const char* name) : 
    Shape(name, x, y), Square(x,y,side_a,name), side_b(side_b) {};

Rectangle::Rectangle(const Rectangle& other): Shape(other.shapeName, other.origin.get_x(), other.origin.get_y()), Square(other), side_b(other.side_b){};

Rectangle& Rectangle::operator=(const Rectangle& rhs){
    if(this != &rhs){
        Square::operator=(rhs);
        side_b = rhs.side_b;
    }
    return *this;
}

double Rectangle::area(){
    return side_a*side_b;
}

double Rectangle::perimeter() {
    return (side_a*2) + (side_b*2);
}

double Rectangle::get_side_b(){
    return side_b;
}

void Rectangle::set_side_b(const double length){
    side_b = length;
}

void Rectangle::display(){
    cout << "\nRectangle Name: " << shapeName
    << "\nX-coordinate: " << origin.get_x() 
    << "\nY-coordinate: " << origin.get_y() 
    << "\nSide a: " << side_a
    << "\nSide b: " << side_b
    << "\nArea: " << area()
    << "\nPerimeter: " << perimeter()
    << "\n" << endl;
}