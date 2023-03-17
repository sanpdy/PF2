//
// Created by Sankalp Pandey on 3/10/23.
//
#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
    count = 0;

}
Stack::Stack(const Stack& copy)
{
    count = copy.count;
}
Stack::~Stack()
{

}

void Stack::push(const int number)
{
    if(!isFull())
    {
        data.push_back(number);
        count ++;
    }
}

int Stack::pop()
{
    if(!(isEmpty()))
    {
        int top = data.back();
        data.pop_back();
        count--;
        return top;
    }
    else
    {
        return -1;
    }
}

int Stack::top() const
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        return data.back();
    }
}

bool Stack::isFull() const
{
    return false;
}

bool Stack::isEmpty() const
{
    if(data.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Stack::getCount() const
{
    //count = data.size();
    return data.size();
}

void Stack::print() const
{
    for(int i = data.size() - 1; i >= 0; i--)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

