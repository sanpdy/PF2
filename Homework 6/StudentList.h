//
// Created by Sankalp Pandey on 4/17/23.
//

#ifndef HOMEWORK6_STUDENTLIST_H
#define HOMEWORK6_STUDENTLIST_H
#include <iostream>
#include <string>
#include "StudentNode.h"
using namespace std;

class StudentList {
private:
    StudentNode *head;

public:
    // Default constructor
    StudentList();

    // Copy constructor
    StudentList(const StudentList &studentList);

    // Destructor
    ~StudentList();

    // Insert a node
    void insert(string name, string country, string city, string gender, double gpa);

    // Delete a node
    void deleteByName(string name);

    // Update a node's attributes
    void updateByName(string name, string country, string city, string gender, double gpa);

    // Returns the size of the linked list
    int getSize() const;

    // Search for a node
    StudentNode *searchByName(string name) const;

    // Print all nodes
    void print() const;
};
#endif //HOMEWORK6_STUDENTLIST_H
