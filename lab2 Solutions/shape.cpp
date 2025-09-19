/*
* File Name: shape.cpp
* Assignment: Lab 2 Exercise B
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept
*/

#include "shape.h"


Shape::Shape(const char* name, const double x, const double y): origin(x,y), shapeName(new char[strlen(name)+1]) {
    strcpy(this->shapeName, name);
} 

Shape::Shape(const Shape& other): origin(other.origin.get_x(), other.origin.get_y()), shapeName(new char[strlen(other.shapeName)+1]) {
    strcpy(shapeName, other.shapeName);
}

Shape& Shape::operator=(const Shape& rhs) {
    if (this != &rhs) {
        char* new_name = new char[strlen(rhs.shapeName)+1];
        strcpy(new_name, rhs.shapeName);
        delete[] shapeName;
        shapeName = new_name;
        origin = rhs.origin;
    }
    return *this;
}

Shape::~Shape(){
    delete[] shapeName;
}

const char* Shape::getName() const {
    return shapeName;
}

void Shape::display(){
    cout << "Shape Name: " << shapeName 
    << "\nX-coordinate: " << origin.get_x()
    << "\nY-coordinate: " << origin.get_y() 
    << "\n" << endl; 
}

double Shape::distance(Shape& other ){
    const double x_distance = other.origin.get_x() - origin.get_x();
    const double y_distance = other.origin.get_y() - origin.get_y();
    return hypot(x_distance, y_distance);
}

double Shape::distance(Shape& the_shape, Shape& other) {
    const double x_distance = the_shape.origin.get_x() - other.origin.get_x();
    const double y_distance = the_shape.origin.get_y() - other.origin.get_y();
    return hypot(x_distance, y_distance);
}

void Shape::move(double dx, double dy){
    origin.set_x(origin.get_x() + dx);
    origin.set_y(origin.get_y() + dy);
}