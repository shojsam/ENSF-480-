/*
* File Name: point.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "point.h"

int Point::count = 1001;

int Point::get_id() const {
    return id;
}

double Point::get_x() const {
    return x_coordinate;
}

double Point::get_y() const {
    return y_coordinate;
}

void Point::set_x(double x) {
    this->x_coordinate = x;
}

void Point::set_y(double y) {
    this->y_coordinate = y;
}

void Point::display() {
    cout << "\nX-coordinate: " << x_coordinate
    << "\nY-coordinate: " << y_coordinate 
    <<"\n" << endl;
}

Point::Point(double a, double b) {
    this->x_coordinate = a;
    this->y_coordinate = b;
    this->id = count;
    count++;
}

int Point::counter() const {
    return count-1000;
}

double Point::distance(const Point& other ){
    const double x_distance = other.x_coordinate - x_coordinate;
    const double y_distance = other.y_coordinate - y_coordinate;
    return hypot(x_distance, y_distance);
}

double Point::distance(const Point& a, const Point& b) {
    const double x_distance = a.x_coordinate - b.x_coordinate;
    const double y_distance = a.y_coordinate - b.y_coordinate;
    return hypot(x_distance, y_distance);
}