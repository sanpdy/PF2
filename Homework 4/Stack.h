//
// Created by Sankalp Pandey on 3/9/23.
//

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    Stack();
    Stack(const Stack& copy);
    ~Stack();

    void push(const int number);
    int pop();
    int top() const;

    bool isFull() const;
    bool isEmpty() const;
    int getCount() const;
    void print() const;

private:
    int count;
    vector <int> data;
};
#endif //_STACK_H_
