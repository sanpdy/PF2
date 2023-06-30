//
// Created by Sankalp Pandey on 4/3/23.
//
#include <iostream>
#include "Book.h"
using namespace std;

// Default constructor
Book::Book()
{
    title = " ";
    lastName = " ";
    firstName = " ";
    genre = " ";
    year = 0;
    rating = 0;
}

// Setter constructor
Book::Book(const int year, const string title, const string lastName, const string firstName, const string genre, const float rating)
{
    this->year = year;
    this->title = title;
    this->lastName = lastName;
    this->firstName = firstName;
    this->genre = genre;
    this->rating = rating;

}

// Copy constructor
Book::Book(const Book &book)
{
    title = book.title;
    lastName = book.lastName;
    firstName = book.firstName;
    genre = book.genre;
    year = book.year;
    rating = book.rating;

}
// Destructor
Book::~Book(){}

// Setters
void Book::setTitle(string title) {this->title = title;}
void Book::setLastName(string lastName) {this->lastName = lastName;}
void Book::setFirstName(string firstName) {this->firstName = firstName;}
void Book::setGenre(string genre) {this->genre = genre;}
void Book::setYear(int year) {this->year = year;}
void Book::setRating(float rating) {this->rating = rating;}

// Getters
string Book::getTitle() const {return title;}
string Book::getLastName() const {return lastName;}
string Book::getFirstName() const {return firstName;}
string Book::getGenre() const {return genre;}
int Book::getYear() const {return year;}
float Book::getRating() const {return rating;}

// Utility
void Book::print()
{
    cout << "Year Published: " << year << endl;
    cout << "Title: " << title << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << endl;
}
