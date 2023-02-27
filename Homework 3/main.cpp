//----------------------------------------------
// Read in your files instead of starting from scratch!
//----------------------------------------------
#include "password.h"
#include <fstream>
#include <iostream>
#include <vector>$
#include <string>
using namespace std;

// PROVIDED
bool readFile(string filename, vector<Password> &list)
{
    string password;
    string rank;
    string hash;
    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din, password, ','))
    {
        getline(din, rank, ',');
        getline(din, hash);
        Password temp (password,stoi(rank),hash);
        list.push_back(temp);
    }
    din.close();
    return 1;
}
// PROVIDED
bool readFile_given_hashes(string filename, vector<string> &list)
{
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din,hash)){
        list.push_back(hash);
    }
    return 1;
}
// ADD SEARCH FUNCTIONS HERE!!



//----------------------------------------------
int main()
{
    //vector for hash sorted file
    vector<Password> hash;
    //vector for password sorted file
    vector<Password> password;
    //vector for hashes to search for
    vector<string> given_hashes;

    readFile("sorted_hash_indexed_list.txt",hash);
    readFile("sorted_password_indexed_list.txt",password);
    readFile_given_hashes("hashes_to_search.txt",given_hashes);

    // ADD YOUR MENU, USER CHOICE, AND IMPLEMENT MENU OPTIONS HERE

    return 0;
}
