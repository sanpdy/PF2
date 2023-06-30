//
// Created by Sankalp Pandey on 4/3/23.
//

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book
{
    private:
        string title, lastName, firstName, genre;
        int year;
        float rating;

    public:
        // Default constructor
        Book();
        // Setter constructor
        Book(const int year, const string title, const string lastName, const string firstName, const string genre, const float rating);
        // Copy constructor
        Book(const Book &book);
        // Destructor
        ~Book();

        // Setters
        void setTitle(string title);
        void setLastName(string lastName);
        void setFirstName(string firstName);
        void setGenre(string genre);
        void setYear(int year);
        void setRating(float rating);

        // Getters
        string getTitle() const;
        string getLastName() const;
        string getFirstName() const;
        string getGenre() const;
        int getYear() const;
        float getRating() const;

        // Utility
        void print();
};

#endif //BOOK_H
