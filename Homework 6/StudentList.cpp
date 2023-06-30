//
// Created by Sankalp Pandey on 4/17/23.
//
#include <iostream>
#include <string>
#include "StudentList.h"
using namespace std;

// Default constructor
StudentList::StudentList()
{
    head = NULL;
}

// Copy constructor
StudentList::StudentList(const StudentList& list)
{
    if (list.head == NULL) {
        head = NULL;
    } else {
        head = new StudentNode(*(list.head));
        StudentNode* current = head;
        while (current->getNext() != NULL) {
            current->setNext(new StudentNode(*(current->getNext())));
            current = current->getNext();
        }
    }
}

// Destructor
StudentList::~StudentList() {
    while (head != NULL) {
        StudentNode* next = head->getNext();
        delete head;
        head = next;
    }
}

// Insert a student node into the list
void StudentList::insert(string name, string country, string city, string gender, double gpa) {
    StudentNode* newNode = new StudentNode(name, country, city, gender, gpa);
    newNode->setNext(head);
    head = newNode;
}

// Delete a student node from the list based on name
void StudentList::deleteByName(string name) {
    if (head == NULL) {
        return;
    }
    if (head->getName() == name) {
        StudentNode* temp = head;
        head = head->getNext();
        delete temp;
        return;
    }
    StudentNode* current = head;
    while (current->getNext() != NULL) {
        if (current->getNext()->getName() == name) {
            StudentNode* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            return;
        }
        current = current->getNext();
    }
}

// Update a student's information based on name/key
void StudentList::updateByName(string name, string country, string city, string gender, double gpa) {
    StudentNode* current = head;
    while (current != NULL) {
        if (current->getName() == name) {
            current->setCountry(country);
            current->setCity(city);
            current->setGender(gender);
            current->setGPA(gpa);
            return;
        }
        current = current->getNext();
    }
}

// Search for a student node in the list based on name/key
StudentNode* StudentList::searchByName(string name) const {
    StudentNode* current = head;
    while (current != NULL) {
        if (current->getName() == name)
        {
            return current;
        }
        current = current->getNext();
    }
    return NULL;
}

// Returns the size of the linked list
int StudentList::getSize() const {
    int count = 0;
    StudentNode* current = head;
    while (current != NULL) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Print all student nodes in the list
void StudentList::print() const {
    StudentNode* current = head;
    while (current != NULL) {
        current->print();
        cout << endl;
        current = current->getNext();
    }
}
