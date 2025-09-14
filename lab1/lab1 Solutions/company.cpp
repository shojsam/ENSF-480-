/*
* File Name: company.cpp
* Assignment: Lab 1 Exercise C
* Lab section: B02
* Completed by: Sam Shojaei
* Development Date: Sept 12, 2025
*/
#include <string>
#include <vector>
using namespace std;

struct Employee {
    string name;
    string lastname;
    Address address;
    string dateOfBirth;
    string state; // active, suspended, retired, fired
};

struct Customer {
    string name;
    string lastname;
    Address address;
    string phone;
};

struct Company {
    string companyName;
    Address companyAddress;
    string dateEstablished;
    vector<Employee> employees;
    vector<Customer> customers;
};
class Address {
    string street;
    string city;
    string province; // or state
    string postalCode;
    string country;
};
