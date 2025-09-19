/*
* File Name: rectangle.h
* Assignment: Lab 2 Exercise B
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept
*/

#include "square.h"

class Rectangle : public Square {
    private:
        double side_b;
    public:
        Rectangle(double x, double y, double side_a, double side_b, const char* name);
        Rectangle(const Rectangle& other);
        Rectangle& operator=(const Rectangle& rhs);

        double area();
        double perimeter();
        double get_side_b();
        void set_side_b(const double length);
        void display();
};