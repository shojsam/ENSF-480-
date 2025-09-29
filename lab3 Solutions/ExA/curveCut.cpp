/*
* File Name: curveCut.cpp
* Assignment: Lab 3 Exercice A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "curveCut.h"

CurveCut::CurveCut(const double x, const double y, const double radius,
        const double side_a, const double side_b, const char* name)
        : Shape(name, x, y), Circle(x, y, radius, name), 
        Rectangle(x, y, side_a, side_b, name) {
            if(radius > side_a || radius > side_b){
                cout << "Radius bigger than side lengths. Program terminating" << endl;
                exit(1);
            }
        };

CurveCut::CurveCut(const CurveCut& other): Shape(other), Circle(other), Rectangle(other) {};

CurveCut& CurveCut::operator=(const CurveCut& rhs){
    if(this != &rhs){
        Shape::operator=(rhs);
        Circle::operator=(rhs);
        Rectangle::operator=(rhs);
    }
    return *this;
};

double CurveCut::area(){
    double circle_area = Circle::area();
    double rectangle_area = Rectangle::area();
    return rectangle_area - (circle_area/4);
};
double CurveCut::perimeter(){
    double circle_perimeter = Circle::perimeter();
    double rectangle_perimeter = Rectangle::perimeter();
    return (rectangle_perimeter - 2*radius) + (circle_perimeter/4);
};

void CurveCut::display(){
    cout << "\nCurveCut Name: " << shapeName
    << "\nX-coordinate: " << origin.get_x() 
    << "\nY-coordinate: " << origin.get_y() 
    << "\nWidth: " << side_a
    << "\nLength: " << side_b
    << "\nRadius of the Cut: " << radius
    << "\n" << endl;
}