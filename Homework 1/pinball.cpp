#include <iostream>
#include <string.h>
#include "pinball.h"
using namespace std;

// default constructor
Pinball::Pinball()
{
    machineName = " ";
    manufacturer = " ";
    theme = " ";
    yearProduced = 0;
    funRating = 0;
}

// parameterized constructor
Pinball::Pinball(const string machineName, const int yearProduced, const string manufacturer, const float funRating, const string theme)
{
    this->machineName = machineName;
    this->manufacturer = manufacturer;
    this->theme = theme;
    this->yearProduced = yearProduced;
    this->funRating = funRating; 
}

// destructor
Pinball::Pinball(const Pinball &pinball)
{
    machineName = pinball.machineName;
    manufacturer = pinball.manufacturer;
    theme = pinball.theme;
    yearProduced = pinball.yearProduced;
    funRating = pinball.funRating;

}

// destructor
Pinball::~Pinball()
{
}

// Getters

string Pinball::getMachineName() const
{
    return machineName;
}

string Pinball::getManufacturer() const
{
    return manufacturer;
}

string Pinball::getTheme() const
{
    return theme;
}

int Pinball::getYearProduced() const
{
    return yearProduced;
}

float Pinball::getFunRating() const
{
    return funRating;
}

// Setters

void Pinball::setMachineName(string machineName)
{
    this->machineName = machineName;
}

void Pinball::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Pinball::setTheme(string theme)
{
    this->theme = theme;
}

void Pinball::setYearProduced(int yearProduced)
{
    this->yearProduced = yearProduced;
}

void Pinball::setFunRating(float funRating)
{
    this->funRating = funRating;
}

// prints the contents of an object
void Pinball::print() const
{
    cout << endl;
    cout << "Machine Name: " << machineName << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Theme:  " << theme << endl;
    cout << "Year Produced: " << yearProduced << endl;
    cout << "Fun Rating: " << funRating << endl;
    cout << endl;

}

