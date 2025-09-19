/*
* File Name: shape.h
* Assignment: Lab 2 Exercise B
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept
*/
#include "point.h"

class Shape{
    protected:
        Point origin;
        char* shapeName;
    public:
        Shape(const char* name, const double x, const double y);
        Shape(const Shape& other);
        Shape& operator=(const Shape& rhs);
        ~Shape();

        Point& getOrigin() const;
        const char* getName() const;

        void virtual display();

        double distance (Shape& other);
        static double distance(Shape& the_shape, Shape& other);
        
        void move (double dx, double dy);
};