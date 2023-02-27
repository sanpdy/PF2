#include "pinball.h"
#ifndef PINBALLTWO_H
#define PINBALLTWO_H
#include <iostream>
using namespace std;

const int MAX_PINBALL_MACHINES = 10;

class PinballTwo{
    private:
    // array for storing machines
    Pinball machines[MAX_PINBALL_MACHINES];
    // integer to track the number of machines
    int numMachines;

    public:
    // default constructor
    PinballTwo(); 
    // copy constructor
    PinballTwo(const PinballTwo &copy);
    // destructor
    ~PinballTwo();

    // getter method to return array size
    int getNumMachines() const;
    
    // insert method to add a new machine
    bool insertMachine(const Pinball& pinball);

    // print utility
    void printAll();
    bool printByYear(int year) const;

    // write file usage
    Pinball getMachines(int index) const;
};

#endif 