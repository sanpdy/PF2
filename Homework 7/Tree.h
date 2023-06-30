#ifndef HOMEWORK_7_TREE_H
#define HOMEWORK_7_TREE_H

#include "Node.h"
#include "Book.h"
class Tree {
private:
    Node* root;

    Node* insertHelper(Node* node, Book book);
    Node* deleteNodeHelper(Node* node, std::string title);
    Node* findMinHelper(Node* node);
    int getHeightHelper(Node* node);
    int getBalanceHelper(Node* node);
    Node* rotateLeftHelper(Node* node);
    Node* rotateRightHelper(Node* node);
    Node* balanceHelper(Node* node);
    void destroyHelper(Node* node);

public:
    Tree();
    ~Tree();
    Book* search(string title);
    void insert(Book book);
    bool deleteNode(string title);
    void balance();
    void print();
    void printHelper(Node* node);
    int getHeight();
    int getSize();
    int getSizeHelper(Node* node);
};

#endif
