// human.h
#include "point.h"
#include <iostream>
#include <cstring>
using namespace std;

class Human {
protected:
    char *name;       // Human's name
    Point location;   // Location of an object of Human on a Cartisian Plain
public:
    
	// Constructor
    Human(const char* nam="", double x=0, double y=0): name(new char[strlen(nam)+1]) {
        strcpy(this ->name, nam);
        location.set_x(x);
        location.set_y(y);
    }
	
	// Copy Constructor
	Human(const Human& other_human): name(new char[strlen(other_human.name)+1]), location(other_human.location) {
		strcpy(name, other_human.name);
	}
	
	
	// Assignment Operator
	Human& operator=(Human& rhs)
	{
		if(this != &rhs){
			char* new_name = new char[strlen(rhs.name)+1];
			strcpy(new_name, rhs.name);
			delete[] name;
			name = new_name;
			location = rhs.location;
		}
		return *this;
	}
		
	// Destructor
	~Human() {
		delete[] name;
	}
    
    const char* get_name() const {return name;} 
            
    void set_name(const char* name) {                  
        this->name = new char[strlen(name)+1];        
        strcpy(this ->name, name);
    }
   
    Point get_point() const {return location;}
    
    void display() {                      
        cout << "Human Name: " << name << "\nHuman Location: "
        << location.get_x() << " ,"
        << location.get_y() << ".\n" << endl;
    }
};