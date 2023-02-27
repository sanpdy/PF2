#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "RestaurantList.h"
#include "RestaurantNode.h"
using namespace std;

// Prints the menu for the user
void printMenu() {
    cout << "----------------------------------" << endl;
    cout << "  Welcome to the Restaurant List  " << endl;
    cout << "----------------------------------" << endl;
    cout << "(1) Add a meal" << endl;
    cout << "(2) Print the list" << endl;
    cout << "(3) Find the highest price" << endl;
    cout << "(4) Change the price of a dish" << endl;
    cout << "(5) Exit menu" << endl;
    cout << "----------------------------------" << endl;
}

int main()
{
    // Initializing variables and objects
    RestaurantList list;
    string choice = " ";
    char userChoice = ' ';

    // This provides error checking
    do
    {
        do
        {
            // Prints the menu
            printMenu();

            // Asks for user choice as a string
            cout << "Enter user choice:" << endl;
            cin >> choice;

            // Converts the first letter of the string to a char.
            // This is to check and make sure multiple characters aren't entered further on.
            userChoice = choice[0];
            cout << endl;
            cin.ignore();
            if(choice.size() > 1)
            {
                cout<<"Error. Choose one of the menu options between 1-5."<<endl;
            }
        }while(!(userChoice == '1' || userChoice == '2' || userChoice == '3' || userChoice == '4' || userChoice == '4' || userChoice == '5') || choice.size() > 1);

        // Switch statement used to access the menu options
        switch (userChoice)
        {
            // Adds a meal
            case '1': {
                string restaurantName, mealName, mealType = " ";
                float restaurantRating, price = 0;
                cout << "Enter Restaurant Name: " << endl;
                getline(cin, restaurantName);
                // Error checking to make sure there's valid input for Restaurant Rating
                do {
                    cout << "Enter Restaurant Rating: " << endl;
                    cin >> restaurantRating;
                    cin.ignore();
                    if(restaurantRating < 0 || restaurantRating > 10)
                    {
                        cout << "Error. Choose a rating between 0-10." << endl;
                    }
                }while(restaurantRating < 0 || restaurantRating > 10);

                cout << "Enter Meal Name: " << endl;
                getline(cin, mealName);
                cout << "Enter Type of Meal: " << endl;
                getline(cin, mealType);
                // Error checking to make sure there's valid input for the price
                do {
                    cout << "Enter Price: " << endl;
                    cin >> price;
                    cin.ignore();
                    if(price < 0)
                    {
                        cout << "Error. Choose a valid price that is at least 0." << endl;
                    }
                }while(price < 0);

                // Actually adds the node to the list
                list.addMeal(restaurantName, restaurantRating, mealName, mealType, price);
                break;
            }
            // Prints the list
            case '2':
                list.print();
                break;

            // Prints the most expensive meal
            case '3': {
                RestaurantNode* exp = list.highestPrice();
                if (exp) {
                    cout << "The most expensive meal is:" << endl;
                    exp->print();
                } else {
                    cout << "The list is empty." << endl;
                }
                break;

            }
            // Asks the user which meal's price they want to change and changes it
            case '4':{
                string mealName;
                cout << "Enter the name of the meal to change the price: ";
                getline(cin, mealName);

                float price = 0;
                do{
                    cout << "Enter the new price: ";
                    cin >> price;
                    cout << endl;

                    if(price < 0)
                    {
                        cout << "Error. Please enter a valid price." << endl;
                    }
                }while(price < 0);
                bool success = list.changePrice(mealName, price);
                if (success) {
                    cout << "The price was changed successfully." << endl;
                } else {
                    cout << "That meal was not found." << endl;
                }
                break;
            }
            // Exits program
            case '5':
                cout << "Exiting program." << endl;
                break;

                // No default is needed because the error checking doesn't allow
                // for there to be an input for which default would be required.
        }
    }while (userChoice != '5');
    return 0;
}