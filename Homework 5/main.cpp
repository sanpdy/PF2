//
// Created by Sankalp Pandey on 4/3/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"
using namespace std;

void readFile(const string filename, vector<Book> & books)
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
        books.push_back(newBook);
    }
    din.close();
}

void writeFile(const string filename, vector<Book> & books)
{
    ofstream dout;
    dout.open(filename);
    if(dout.fail())
    {
        cout << "ERROR: OUTPUT FILE COULD NOT BE OPENED" << endl;
        exit (EXIT_FAILURE);
    }
    for(int i = 0; i < books.size(); i++)
    {
        dout << books[i].getYear() << ", " << books[i].getTitle() << ", " << books[i].getLastName() << ", " << books[i].getFirstName() << ", " << books[i].getGenre() << ", " << books[i].getRating() << ", " << endl;
    }
    dout.close();
}

// Quick sort by year, increasing
void partition(vector<Book>& books, int low, int high, int& mid) {
    // Use data[high] for pivot value
    int pivot = books[high].getYear();

    // Partition array into two parts
    int left = low;
    int right = high - 1;
    while (left <= right) {
        // Scan left to right
        while (left <= right && books[left].getYear() <= pivot) {
            left++;
        }
        // Scan right to left
        while (left <= right && books[right].getYear() >= pivot) {
            right--;
        }
        // Swap data values
        if (left < right) {
            Book temp = books[left];
            books[left] = books[right];
            books[right] = temp;
        }
    }
    // Swap pivot to mid
    mid = left;
    Book temp = books[high];
    books[high] = books[mid];
    books[mid] = temp;
}

// Quick Sort by Year, increasing
void quickSort(vector<Book> & books, int low, int high)
{
    // Check terminating condition
    if (low < high)
    {
        // Partition data into two parts
        int mid = 0;
        partition(books, low, high, mid);

        // Recursive calls to sort array
        quickSort(books, low, mid - 1);
        quickSort(books, mid + 1, high);
    }
}

// Merge Sort by Rating Descending
void mergeSort(vector<Book> & books, int low, int high) {
    // Check terminating condition
    if(low >= high)
    {
        return;
    }
    // Divide the array and sort both halves
    int mid = (low + high) / 2;
    mergeSort(books, low, mid);
    mergeSort(books, mid + 1, high);

    // Merge sorted arrays
    // Create temporary array for merged data
    vector<Book> temp;

    // Initialize array indices
    int index1 = low;
    int index2 = mid + 1;
    while (index1 <= mid && index2 <= high) {
        if (books[index1].getRating() >= books[index2].getRating()) {
            temp.push_back(books[index1]);
            index1++;
            }
        else {
            temp.push_back(books[index2]);
            index2++;
            }
        }
    // Copy any remaining entries from the first half
    while (index1 <= mid) {
            temp.push_back(books[index1]);
            index1++;
    }

    // Copy any remaining entries from the second half
    while (index2 <= high) {
            temp.push_back(books[index2]);
            index2++;
    }

    // Copy data back from the temporary array
    for (int i = low; i < high; i++)
    {
        books[i] = temp[i - low];
    }
}

// Selection Sort by Title in Alphabetical Order
void selectionSort(vector<Book> & books, int low, int high)
{
    // Loop over input array N times
    for (int last = high; last > low; last--)
    {
        int largest = low;
        for (int index = low + 1; index <= last; index++)
        {
            string title1 = books[index].getTitle();
            string title2 = books[largest].getTitle();
            // Ignore "The"
            if (title1.substr(0, 4) == "The ")
                title1 = title1.substr(4);
            if (title2.substr(0, 4) == "The ")
                title2 = title2.substr(4);
            if (title1 > title2)
                largest = index;
        }
        // Swap with last element in unsorted array
        Book temp = books[last];
        books[last] = books[largest];
        books[largest] = temp;
    }
}

void insertionSort(vector<Book> & books, int low, int high)
{
    // Insert each element of unsorted list into sorted list
    for (int unsorted = low + 1; unsorted <= high; unsorted++)
    {
        // Select unsorted value to be inserted
        Book value = books[unsorted];
        int posn = unsorted-1;

        // Make room for new data value
        while (posn >= low && books[posn].getLastName() > value.getLastName())
        {
            books[posn+1] = books[posn];
            posn--;
        }
        // Put new value into array
        books[posn+1] = value;
    }
}

int main() {
    // Declare variable of class Book
    vector<Book> books;

    // Read the books.csv file into the books vector
    readFile("books.csv", books);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     WELCOME TO THE HOMEWORK 5     " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    cout << "Quick Sort Algorithm Beginning..." << endl;
    // Code to time algorithm
    clock_t start = clock();
    // Quick Sort algorithm
    quickSort(books, 0, books.size() -1);
    clock_t end = clock();
    double runtime = (end - start) / double(CLOCKS_PER_SEC);
    cout << "Run time for Quick Sort algorithm: " << runtime << " seconds" << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    // Write the vector into a csv file
    writeFile("QuickSortByYear.csv", books);

    cout << "Merge Sort Algorithm Beginning..." << endl;
    clock_t start2 = clock();
    // Merge Sort algorithm
    mergeSort(books, 0, books.size() -1);
    clock_t end2 = clock();
    double runtime2 = (end2 - start2) / double(CLOCKS_PER_SEC);
    cout << "Run time for Merge Sort algorithm: " << runtime2 << " seconds" << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    // Write the vector into a csv file
    writeFile("MergeSortByRatingDescending.csv", books);

    cout << "Selection Sort Algorithm Beginning..." << endl;
    clock_t start3 = clock();
    // Selection Sort algorithm
    selectionSort(books, 0, books.size() -1);
    clock_t end3 = clock();
    double runtime3 = (end3 - start3) / double(CLOCKS_PER_SEC);
    cout << "Run time for Selection Sort algorithm: " << runtime3 << " seconds" << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    // Write the vector into a csv file
    writeFile("SelectionSortByTitleAlphabetical.csv", books);

    cout << "Insertion Sort Algorithm Beginning..." << endl;
    clock_t start4 = clock();
    // Insertion Sort algorithm
    insertionSort(books, 0, books.size() -1);
    clock_t end4 = clock();
    double runtime4 = (end4 - start4) / double(CLOCKS_PER_SEC);
    cout << "Run time for Insertion Sort algorithm: " << runtime4 << " seconds" << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    // Write the vector into a csv file
    writeFile("InsertionSortByLastNameAlphabetical.csv", books);

    // Indicates that all the algorithms are done being ran and timed
    cout << "All algorithms timed." << endl;
    return 0;
}
