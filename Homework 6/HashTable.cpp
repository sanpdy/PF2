//
// Created by Sankalp Pandey on 4/19/23.
//
#include <iostream>
#include <string>
#include "StudentList.h"
#include "HashTable.h"
using namespace std;

// Private Hash function
int HashTable::hash(string key) const
{
    unsigned int sum = 0;
    for (size_t i = 0; i < key.length(); i++) {
        sum += key[i];
    }
    return sum % size;
}

// Non-Default constructor
HashTable::HashTable(int size)
{
    this->size = size;
    count = 0;
    collisions = 0;
    hashtable = new StudentList[size];
}

// Default constructor
HashTable::HashTable()
{
    count = 0;
    size = 300;
    collisions = 0;
    hashtable = new StudentList[size];
}

// Copy constructor
HashTable::HashTable(const HashTable& copy)
{
    count = copy.count;
    size = copy.size;
    collisions = copy.collisions;
    hashtable = new StudentList[size];
    for (int i = 0; i < size; i++)
    {
        hashtable[i] = copy.hashtable[i];
    }
}

// Destructor
HashTable::~HashTable()
{
    delete[] hashtable;
}

// Insert a node
void HashTable::insert(StudentNode* node)
{
    int index = hash(node->getName());
    if (hashtable[index].searchByName(node->getName()) != NULL)
    {
        return; // node already exists
    }
    hashtable[index].insert(node->getName(), node->getCountry(), node->getCity(), node->getGender(), node->getGPA());
    count++;
    if (hashtable[index].getSize() > 1)
    {
        collisions++;
    }
}

// Delete a node
void HashTable::deleteByName(string name)
{
    int index = hash(name);
    StudentNode* node = hashtable[index].searchByName(name);
    if (node == NULL)
    {
        cout << "Student not found" << endl;
        return;
    }
    hashtable[index].deleteByName(name);
    count--;
}

// Update a node's attributes
void HashTable::updateByName(string name, string country, string city, string gender, double gpa)
{
    int index = hash(name);
    StudentNode* node = hashtable[index].searchByName(name);
    if (node == NULL)
    {
        cout << "Student not found" << endl;
        return;
    }
    cout << "Enter country: ";
    getline(cin, country);
    cout << "Enter city: ";
    getline(cin, city);
    cout << "Enter gender: ";
    getline(cin, gender);
    do
    {
        cout << "Enter GPA: ";
        cin >> gpa;
        if(gpa < 0)
        {
            cout << "Enter a GPA higher than 0." << endl;
        }
    }while(gpa < 0);
    node->setCountry(country);
    node->setCity(city);
    node->setGender(gender);
    node->setGPA(gpa);
}


// Search for a node
void HashTable::searchByName(string name) const
{
        int index = hash(name);
        StudentNode* node = hashtable[index].searchByName(name);
        if (node != NULL)
        {
            node->print();
        }
        else
        {
            cout << "Student not found" << endl;
        }
}

// Print all nodes
void HashTable::print() const
{
    for (int i = 0; i < size; i++)
    {
        hashtable[i].print();
            cout << endl;
    }
}

// Getter methods for Hashtable statistics
int HashTable::getCount() const { return count; }
int HashTable::getSize() const { return size; }
int HashTable::getCollisions() const { return collisions; }
