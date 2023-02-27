#ifndef PINBALL_H
#define PINBALL_H
#include <iostream>
using namespace std;


class Pinball
{
  private:
   string machineName;
   string manufacturer;
   string theme;
   int yearProduced;
   float funRating;

 public:
   // Default constructor
   Pinball();

   // Setter constructor
  Pinball(const string machineName, const int yearProduced, const string manufacturer, const float funRating, const string theme);  
  // Copy constructor
  Pinball(const Pinball &pinball);

  //Destructor
   ~Pinball();

   // Getters
   string getMachineName() const;
   string getManufacturer() const;
   string getTheme() const;
   int getYearProduced() const;
   float getFunRating() const;

    // Setters

   void setMachineName(string machineName);
   void setManufacturer(string manufacturer);
   void setTheme(string theme);
   void setYearProduced(int yearProduced);
   void setFunRating(float funRating);

   // Utility 
   void print() const;

};




#endif

