//
// Created by Sankalp Pandey on 4/17/23.
//

#ifndef HOMEWORK6_STUDENTNODE_H
#define HOMEWORK6_STUDENTNODE_H

#include <iostream>
#include <string>
using namespace std;
class StudentNode
{
    private:
        //name and key
        string name;
        string country;
        string city;
        string gender;
        float gpa;
        StudentNode* next;

    public:
        // Default constructor
        StudentNode();
        // Overloaded constructor
        StudentNode(string name, string city, string country, string gender, float gpa);
        // Copy constructor
        StudentNode(const StudentNode& studentNode);
        // Destructor
        ~StudentNode();

        // Getters
        string getName() const;
        string getCountry() const;
        string getCity() const;
        string getGender() const;
        float getGPA() const;
        StudentNode* getNext() const;

        // Setters
        void setName(string name);
        void setCountry(string country);
        void setCity(string city);
        void setGender(string gender);
        void setGPA(float gpa);
        void setNext(StudentNode* next);

        // Utility
        void print() const;
};
#endif //HOMEWORK6_STUDENTNODE_H
