#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "StudentNode.h"
#include "StudentList.h"
using namespace std;

// Reads the txt file and inserts it into the table
void readFile(const string filename, HashTable& table)
{
    string name, country, city, gender, gpa;
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
    {
        cout << "Error. file " << filename << " could not be opened." << endl;
        return;
    }
    while (!din.eof())
    {
        getline(din, name, ',');
        getline(din, country, ',');
        getline(din, city, ',');
        getline(din, gender, ',' );
        getline(din, gpa);
        StudentNode* student = new StudentNode(name, country, city, gender, stof(gpa));
        table.insert(student);
    }
    din.close();
}

// Used to prompt the user for input
void getUserData(string &name, string &country, string &city, string &gender, float &gpa)
{
    cout << "Enter student name: ";
    getline(cin, name);
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
}

// Used by several cases in main to store a value for the key
string getName()
{
    string name;
    cout << "Enter the name:" << endl;
    getline(cin, name);
    return name;
}

// Prints the menu
void printMenu()
{
    cout << endl << "Homework 6 Menu:" << endl;
    cout << "~~~~~~~~~~~~~~~~" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Update" << endl;
    cout << "4. Search" << endl;
    cout << "5. Print" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): " << endl;
}

// Main
int main() {
    HashTable table;
    readFile("student-dataset.txt", table);

    int choice;
    do {
        // Print menu options
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
            {
                // Insert a new node
                string name, country, city, gender;
                float gpa;
                cout << endl << "-------------------" << endl << "Insertion selected." << endl << "-------------------" << endl;
                getUserData(name, country, city, gender, gpa);
                StudentNode* student = new StudentNode(name, country, city, gender, gpa);
                table.insert(student);
                break;
            }
            case 2:
            {
                // Delete a node
                cout << endl << "-------------------" << endl << "Deletion selected." << endl << "-------------------" << endl;
                string key = getName();
                table.deleteByName(key);
                break;
            }
            case 3:
            {
                // Update a node
                cout << endl << "-------------------" << endl << "Update selected." << endl << "-------------------" << endl;
                string key = getName();
                string country = " ", city = " ", gender = " ";
                float gpa = 0;
                table.updateByName(key, country, city, gender, gpa);
                break;
            }
            case 4:
            {
                // Search for a node and print it
                cout << endl << "-------------------" << endl << "Search selected." << endl << "-------------------" << endl;
                string key = getName();
                cout << endl;
                table.searchByName(key);
                break;
            }
            case 5:
            {
                // Print the entire hash table
                cout << endl << "-------------------" << endl << "Print selected." << endl << "-------------------" << endl << endl;
                table.print();
                break;
            }
            case 6:
            {
                // Exit
                break;
            }
            default:
            {
                // Error Checking for invalid choice
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                break;
            }
        }
    } while (choice != 6);

    // Print hashtable stats
    cout << "Hashtable statistics: " << endl;
    cout << "  Count: " << table.getCount() << endl;
    cout << "  Size: " << table.getSize() << endl;
    cout << "  Collisions: " << table.getCollisions() << endl;

    return 0;
}

