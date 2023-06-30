//
// Created by Sankalp Pandey on 4/17/23.
//
#include <iostream>
#include <string>
#include "StudentNode.h"
#include <iomanip>
using namespace std;

// Default constructor
StudentNode::StudentNode()
{
    name = " ";
    country = " ";
    city = " ";
    gender = " ";
    gpa = 0;
    next = NULL;
}
// Overloaded constructor
StudentNode::StudentNode(string name, string city, string country, string gender, float gpa)
{
    this->name = name;
    this->city = city;
    this->country = country;
    this->gender = gender;
    this->gpa = gpa;
}
// Copy constructor
StudentNode::StudentNode(const StudentNode& studentNode)
{
    this->name = studentNode.name;
    this->city = studentNode.city;
    this->country = studentNode.country;
    this->gender = studentNode.gender;
    this->gpa = studentNode.gpa;
    next = NULL;
}
// Destructor
StudentNode::~StudentNode(){}

// Getters
string StudentNode::getName() const {return name;}
string StudentNode::getCountry() const {return country;}
string StudentNode::getCity() const {return city;}
string StudentNode::getGender() const {return gender;}
float StudentNode::getGPA() const {return gpa;}
StudentNode* StudentNode::getNext() const {return next;}

// Setters
void StudentNode::setName(string name){this->name = name;}
void StudentNode::setCountry(string country){this->country = country;}
void StudentNode::setCity(string city){this->city = city;}
void StudentNode::setGender(string gender){this->gender = gender;}
void StudentNode::setGPA(float gpa){this->gpa = gpa;}
void StudentNode::setNext(StudentNode* next){this->next = next;}

// Utility
void StudentNode::print() const {
    cout << "Name: " << name << endl;
    cout << "Country: " << country << endl;
    cout << "City: " << city << endl;
    cout << "Gender: " << gender << endl;
    cout << "GPA: " << fixed << setprecision(1) << gpa << endl;
}