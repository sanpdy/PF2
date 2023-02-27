#include "pinballTwo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// default constructor
PinballTwo::PinballTwo()
{
    numMachines = 0;
}

// copy constructor
PinballTwo::PinballTwo(const PinballTwo &copy)
{
    numMachines = copy.numMachines;
    for(int i = 0; i < MAX_PINBALL_MACHINES; i++){
        machines[i] = copy.machines[i];
    }
}

// destructor
PinballTwo::~PinballTwo()
{
}

// getter for array size
int PinballTwo::getNumMachines() const
{
    return numMachines;
}

// method to add machines to the array
bool PinballTwo::insertMachine(const Pinball& pinball)
{
    if(numMachines > 10)
    {
        cout << "Error: There are already 10 machines." << endl;
        return false;
    }
    machines[numMachines++] = pinball;
    return true;
}

// prints all of the machines
void PinballTwo::printAll()
{
    cout << "Machines" << endl;
    cout << "~~~~~~~~" << endl;
    for(int i = 0; i < numMachines; i++)
    {
        machines[i].print();
    }
}

// prints machines from a specific year
bool PinballTwo::printByYear(int year) const
{
    bool found = false;
    for(int i = 0; i < numMachines; i++)
    {
        float yearProduced = machines[i].getYearProduced();
        if(yearProduced == year)
        {
            cout << "Machines" << endl;
            machines[i].print();
            found = true;
        }
    }
    return found;
}
// used in the writefile
Pinball PinballTwo::getMachines(int index) const
{
  if (index < 0 || index >= numMachines)
  {
    // print error message and return  Animal
    cout << "Error: invalid index for shopping cart" << endl;
    return Pinball();
  }
  return machines[index];
}
