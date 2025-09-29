/*
* File Name: curveCut.h
* Assignment: Lab 3 Exercice A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "circle.h"
#include "rectangle.h"

class CurveCut : public Circle, public Rectangle {
    private:
    public:
    CurveCut(const double x, const double y, const double radius,
        const double side_a, const double side_b, const char* name);
    
    CurveCut(const CurveCut& other);

    CurveCut& operator=(const CurveCut& rhs);

    double area();
    double perimeter();
    void display();
};