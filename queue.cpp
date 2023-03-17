//
// Created by Sankalp Pandey on 3/13/23.
//
#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue()
{
    count = 0;
}

Queue::Queue(const Queue& copy)
{
    count = copy.count;
}
Queue::~Queue()
{

}

void Queue::insert(const int number)
{
    if(!isFull())
    {
        data.push_back(number);
    }
}
int Queue::remove()
{
    if(!isEmpty()){
        int value = data.front();
        data.erase(data.begin());
        return value;
    }
    else
    {
        return -1;
    }
}

bool Queue::isFull() const
{
    return false;
}
bool Queue::isEmpty() const
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
int Queue::getCount() const
{
    return data.size();
}
void Queue::print() const
{
    for(int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

