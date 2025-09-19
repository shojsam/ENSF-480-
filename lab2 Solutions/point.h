/*
* File Name: point.h
* Assignment: Lab 2 Exercise B
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept
*/

#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        double x_coordinate;
        double y_coordinate;
        int id;
        static int count;
    public:
        int get_id() const;
        double get_x() const;
        double get_y() const;

        void set_x(double x);
        void set_y(double y);

        void display();
        
        Point (double a, double b);

        int counter() const;

        double distance(const Point& other);

        static double distance(const Point& a, const Point& b);
};