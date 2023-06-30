//
// Created by Sankalp Pandey on 5/2/23.
//
#include <iostream>
#include "Node.h"

Node::Node(Book book)
{
        this->book = book;
        left = NULL;
        right = NULL;
}