/*
* File Name: point.h
* Assignment: Lab 1 Exercise D
* Lab section: B02
* Completed by: Luke Chayer
* Development Date: Sept 9, 2025
*/
class Point{
private:
    double x;     // x coordinate of a location on Cartisian Plain
    double y;     // y coordinate of a location on Cartisian Plain
public:
    Point(double a =0, double b =0): x(a), y(b) {}
    double get_x() const {return x;}
    double get_y() const {return y;}
    void set_x(double a) { x = a;};
    void set_y(double a) { y = a;};
};