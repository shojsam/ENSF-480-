/*
* File Name: circle.h
* Assignment: Lab 3 Exercice A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "shape.h"

class Circle : virtual public Shape {
    protected:
    double radius;

    public:
    Circle(const double x, const double y, const double radius, const char* name);
    Circle(const Circle& other);
    Circle& operator=(const Circle& rhs);

    double area();
    double perimeter();
    const double get_radius() const;
    void set_radius(const double radius);
    void display();

};
