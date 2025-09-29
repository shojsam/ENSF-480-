/*
* File Name: square.h
* Assignment: Lab 3 Exercise A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "shape.h"

class Square : virtual public Shape {
    protected:
        double side_a;
    public:
        Square (double x, double y, double side_a, const char* name);
        Square (const Square& other_square);
        Square& operator=(const Square& rhs);

        double area();
        double perimeter();
        double const get_side_a();
        void set_side_a(double length);

        void display();
};