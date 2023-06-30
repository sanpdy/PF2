#include <iostream>
#include <fstream>
#include "Node.h"
#include "Book.h"
#include "Tree.h"
using namespace std;

// read the file and load it into the tree
void readFile(const string filename, Tree& tree)
{
    string year, title, lastName, firstName, genre, rating;
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
        getline(din, year, ',');
        if(year == "\n")
        {
            break;
        }
        getline(din, title, ',');
        getline(din, lastName, ',');
        getline(din, firstName, ',' );
        getline(din, genre, ',' );
        getline(din, rating, ',');

        Book newBook(stoi(year), title, lastName, firstName, genre, stof(rating));
        tree.insert(newBook);
    }
    din.close();
}

// search for a book in the tree by title
void search(Tree& tree) {
    cout << endl;
    string title;
    cout << "Enter book title to search: ";
    cin.ignore();
    getline(cin, title);
    Book* searchBook = tree.search(title);
    if (searchBook == NULL) {
        cout << "Book not found." << endl;
    }
    else {
        searchBook->print();
        cout << endl;
    }
}


// insert a new book into the tree
void insert(Tree& tree)
{
    cout << endl;
    string year, title, lastName, firstName, genre, rating;
    cout << "Enter publication year: ";
    cin.ignore();
    getline(cin, year);
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author's last name: ";
    getline(cin, lastName);
    cout << "Enter author's first: ";
    getline(cin, firstName);
    cout << "Enter book genre: ";
    getline(cin, genre);
    cout << "Enter book rating: ";
    getline(cin, rating);

    Book book(stoi(year), title, lastName, firstName, genre, stof(rating));
    tree.insert(book);

    cout << "Book inserted successfully." << endl;
}

// delete a book from the tree by title
void remove(Tree& tree) {
    string title;
    cout << "Enter book title to delete: ";
    cin.ignore();
    getline(cin, title);
    if (tree.deleteNode(title)) {
        cout << "Book deleted successfully." << endl;
    } else {
        cout << "Book not found." << endl;
    }
}

// prints the tree contents, size, and height
void print(Tree& tree) {
    tree.print();
    cout << "Total nodes: " << tree.getSize() << endl;
    cout << "Tree height: " << tree.getHeight() << endl;
}

// prints the menu
void menu()
{
    cout << endl;
    cout << "HOMEWORK 7" << endl;
    cout << "~~~~~~~~~~" << endl;
    cout << "1) Load " << endl <<
            "2) Search"  << endl <<
            "3) Insert" << endl <<
            "4) Delete" << endl <<
            "5) Print" << endl <<
            "6) Quit" << endl;
    cout << "~~~~~~~~~~" << endl;
}

int main()
{
    Tree tree;
    int choice = 0;

    while(choice != 6)
    {
        menu();
        cin >> choice;
        if((choice < 1) || (choice > 6))
        {
            cout << "Error. Enter 1-6" << endl;
        }
        switch (choice) {
            case 1:
                readFile("books.csv", tree);
                break;
            case 2:
                search(tree);
                break;
            case 3:
                insert(tree);
                break;
            case 4:
                remove(tree);
                break;
            case 5:
                print(tree);
                break;
            case 6:
                cout << "Quitting." << endl;
                break;

            default:
                // Error Checking for invalid choice
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
        }
    }
    return 0;
}
