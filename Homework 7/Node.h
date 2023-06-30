//
// Created by Sankalp Pandey on 5/2/23.
//

#ifndef HOMEWORK_7_NODE_H
#define HOMEWORK_7_NODE_H

#include "Book.h"
#include <iostream>
using namespace std;

class Node {
    public:
        Book book;
        Node* left;
        Node* right;
        int height;

        Node();
        Node(Book book);
};


#endif //HOMEWORK_7_NODE_H
