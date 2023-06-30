//
// Created by Sankalp Pandey on 4/19/23.
//

#ifndef HOMEWORK6_HASHTABLE_H
#define HOMEWORK6_HASHTABLE_H

#include <iostream>
#include <string>
#include "StudentList.h"
#include "StudentNode.h"
using namespace std;

class HashTable {
private:

    int count; // number of nodes in the hashtable
    int size; // size of the array
    int collisions; // total collisions
    StudentList* hashtable; // array of student lists

    // Hash function: returns an index in the range [0, size-1]
    int hash(string key) const;

public:

    // Non-default constructor
    HashTable(int size);

    // Default constructor
    HashTable();

    // Copy constructor
    HashTable(const HashTable& table);

    // Destructor
    ~HashTable();

    // Insert a node
    void insert(StudentNode* node);

    // Delete a node
    void deleteByName(string name);

    // Update a node's attributes
    void updateByName(string name, string country, string city, string gender, double gpa);

    // Search for a student node in the hashtable based on full name
    void searchByName(string name) const;

    // Print all student nodes in the hashtable
    void print() const;

    // Getter methods for the Hashtable statistics
    int getCount() const;
    int getSize() const;
    int getCollisions() const;
};

#endif //HOMEWORK6_HASHTABLE_H
