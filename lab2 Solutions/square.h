/*
* File Name: square.h
* Assignment: Lab 2 Exercise B
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept
*/

#include "shape.h"

class Square : public Shape {
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