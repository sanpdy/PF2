#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "pinball.h"
#include "pinballTwo.h"

void readFile(const string filename, PinballTwo &pinballs)
{
    // opens file, and checks if it failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail())
    {
        cout << "Error. file " << filename << " could not be opened." << endl;
        return;
    }
    // local temporary variables to read data
    string machineName, manufacturer, theme, year, rating;

    while (!din.eof())
    {
        // reads in data
        getline(din, machineName, ',');
        getline(din, year, ',');
        getline(din, manufacturer, ',');
        getline(din, rating, ',');
        getline(din, theme);

        // converts the production year and average fun rating from strings to an integer and a float, respectively
        int yearProduced = stoi(year);
        float funRating = stof(rating);

        // new Pinball object which is inserted into the machine list
        Pinball newPinball(machineName, yearProduced, manufacturer, funRating, theme);
        if (!din.eof())
            pinballs.insertMachine(newPinball);
    }
    din.close();
}

void writeFile(const string filename, PinballTwo pinballs)
{
    // open file for output, check if failed
    ofstream dout;
    dout.open(filename.c_str());

    if (dout.fail())
    {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // loop for each index in the userCart array, write data of each Animal object to output file in CSV formats
    for (int i = 0; i < pinballs.getNumMachines(); i++)
    {
        Pinball pinball = pinballs.getMachines(i);
        dout << pinball.getMachineName() << ','
             << pinball.getYearProduced() << ','
             << pinball.getManufacturer() << ','
             << pinball.getFunRating() << ','
             << pinball.getTheme() << endl;
    }
    dout.close();
}



void printMenu()
{
    // prints menu
    cout << "\nWelcome!"
         << "\n1: Load machines from an ASCII file."
         << "\n2: Insert a new machine."
         << "\n3: Print machines from a given year."
         << "\n4: Print information for all machines."
         << "\n5: Exit program."
         << endl;
}

char getUserChoice()
{
    // makes sure the user's choice is between 1 and 5
    char userChoice = '0';
    do
    {
        cout << "\nEnter menu selection: ";
        cin >> userChoice;
        if (!(userChoice == '1' || userChoice > '2'|| userChoice > '3'|| userChoice > '4'|| userChoice > '5'))
            cout << "\nError: invalid input. Please try again." << endl;
    }while(!(userChoice == '1' || userChoice > '2'|| userChoice > '3'|| userChoice > '4'|| userChoice > '5'));
    
    return userChoice;
}


int main()
{
    // declare PinballTwo object
    PinballTwo pinballs;

    // print menu and get user choice
    char userChoice = ' ';

    // loop until user decides to exit program
    do
    {   
        do
        {
        printMenu();
        cout << "Enter user choice:";
        cin >> userChoice;
    }while (!(userChoice >= '1' && userChoice <= '5'));

        switch (userChoice)
        {
        case '1':
            // reads in data from file if user wants to load machines from ASCII file
            readFile("pinball.txt", pinballs);
            break;
        case '2':
        {
            // local variables that will be used to add a new machine
            string machineName, manufacturer, theme;
            int yearProduced;
            float funRating;
            cout << "Enter the machine's name: " << endl;
            cin.ignore();
            getline(cin, machineName);
            
            // error checking on the production year, technically negative years could just be BC, but I just wanted to keep it to AD
            do
            {
                cout << "Enter the production year: " << endl;
                cin >> yearProduced;
                if (yearProduced < 0)
                {
                    cout << "Error. Please enter a positive year: " << endl;
                }
            } while (yearProduced < 0);

            cout << "Enter the manufacturer: " << endl;
            cin.ignore();
            getline(cin, manufacturer);
            
            // error checking to make sure fun rating isn't higher than 10 or negative
            do
            {
                cout << "Enter the average fun rating from 0-10: " << endl;
                cin >> funRating;
                if (funRating < 0)
                {
                    cout << "Error. Please enter an average fun rating that's a positive number: " << endl;
                }
                if (funRating > 10)
                {
                    cout << "Error. Please enter an average fun rating that's not greater than 10: " << endl;
                }
            } while (funRating < 0 || funRating > 10);
            cout << "Enter the theme(s): " << endl;
            cin.ignore();
            getline(cin, theme);
            Pinball newPinball(machineName, yearProduced, manufacturer, funRating, theme);
            pinballs.insertMachine(newPinball);
            break;
        }
        case '3':
            cout << endl;
            int year;

            // error checking to make sure user puts in a positive year
            do
            {
                cout << "Enter a year to see which machines were produced during it: " << endl;
                cin >> year;
                if (year < 0)
                {
                    cout << "Error. Please enter a year that's positive" << endl;
                }

            } while (year < 0);

            bool found;
            found = pinballs.printByYear(year);

            if(found){
                cout << "Machines" << endl;
                cout << "~~~~~~~~" << endl;
            }
            
            // if nothing from that year is found
            if (!found)
            {
                cout << endl;
                cout << "Sorry no machines were found from that year." << endl;
            }
            break;

        case '4':
            cout << endl;
            pinballs.printAll();
            break;
        case '5':
            writeFile("pinball.txt", pinballs);
            break;
        default:
            cout << "Error: Please type in a valid input." << endl;
            break;
        }

    }while (!(userChoice == '5'));

    return 0;
}
