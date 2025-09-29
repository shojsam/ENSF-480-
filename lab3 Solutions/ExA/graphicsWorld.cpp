/*
* File Name: graphicsWorld.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B02
* Completed by: Luke Chayer
* Submission Date: Sept 29, 2025
*/

#include "graphicsWorld.h"

void GraphicsWorld::run() {
	//Portion of previous lab to work with new lab code
	Square s(5, 7, 12, "SQUARE - S");
	Rectangle a(5, 7, 12, 15, "RECTANGLE A");
	Rectangle b(16, 7, 8, 9, "RECTANGLE B");
	double d = a.distance(b);
	Rectangle rec1 = a;
	Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
	rec2 = a;
	a.set_side_b(200);
	a.set_side_a(100);
	Rectangle rec3 (a);
	a.set_side_b(300);
	a.set_side_a(400);

// New lab portion of run()
	cout << "\nWelcome to Graphics world! Now with circles and curve cut features!" <<endl;
	cout << "\nCreated by Luke Chayer and Sam Shojaei." <<endl;
	cout << "\nTesting Functions in class Circle:" <<endl;
	Circle c (3, 5, 9, "CIRCLE C");
	c.display();
	cout << "\nthe area of " << c.getName() <<" is: "<< c.area() << endl;
	cout << "\nthe perimeter of " << c.getName() << " is: "<< c.perimeter() << endl;
	d = a.distance(c);
	cout << "\nThe distance between rectangle a and circle c is: " <<d;
	CurveCut rc (6, 5, 9, 12, 10, "CurveCut rc");
	rc.display();
	cout << "\nthe area of " << rc.getName() <<" is: "<< rc.area();
	cout << "\nthe perimeter of " << rc.getName() << " is: "<< rc.perimeter();
	d = rc.distance(c);
	cout << "\nThe distance between rc and c is: " <<d;
// Using array of Shape pointers:
	Shape* sh[4];
	sh[0] = &s;
	sh[1] = &a;
	sh [2] = &c;
	sh [3] = &rc;
	sh [0]->display();
	cout << "\nthe area of "<< sh[0]->getName() << " is: "<< sh[0] ->area();
	cout << "\nthe perimeter of " << sh[0]->getName () << " is: "<< sh[0]->perimeter();
	sh [1]->display();
	cout << "\nthe area of "<< sh[1]->getName() << " is: "<< sh[1] ->area();
	cout << "\nthe perimeter of " << sh[0]->getName () << " is: "<< sh[1]->perimeter();
	sh [2]->display();
	cout << "\nthe area of "<< sh[2]->getName() << " is: "<< sh[2] ->area();
	cout << "\nthe circumference of " << sh[2]->getName ()<< " is: "<< sh[2]->perimeter();
	sh [3]->display();
	cout << "\nthe area of "<< sh[3]->getName() << " is: "<< sh[3] ->area();
	cout << "\nthe perimeter of " << sh[3]->getName () << " is: "<< sh[3]->perimeter();
	cout << "\nTesting copy constructor in class CurveCut:" <<endl;
	CurveCut cc = rc;
	cc.display();
	cout << "\nTesting assignment operator in class CurveCut:" <<endl;
	CurveCut cc2(2, 5, 9, 12, 100, "CurveCut cc2");
	cc2.display();
	cc2 = cc;
	cc2.display();
} // END OF FUNCTION run



int main(void) {
    GraphicsWorld::run();
    return 0;
}