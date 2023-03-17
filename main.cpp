#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <time.h>
#include <cstdlib>
using namespace std;

int printMenu()
{
    int numTests;
    do {
        cout << "How many calls would you like to run?" << endl;
        cin >> numTests;
        if(numTests <= 0)
        {
            cout << "Error - Choose an integer greater than 0" << endl;
        }
        else if (numTests > 2147483647)
        {
            cout << "Error - Choose an integer that is smaller but still positive." << endl;
        }
    }while((numTests <= 0) || (numTests > 2147483647));
    cout << endl;
    return numTests;
}

void stackRun(int numTests)
{
    Stack stack;
    // loop numTests times
    for (int i = 0; i < numTests; i++) {
        // generate a random number between 0 and 1
        int r = rand() % (101);
        if (r < 51) {
            // push a random value onto the stack
            int value = rand() % 101;
            stack.push(value);
        } else {
            // pop a value from the stack (if it's not empty)
            if (!stack.isEmpty()){
                stack.pop();
            }
        }
    }
    // prints the stack
    cout << "Stack: " << endl;
    stack.print();
    // print the size of the stack (should be around 20)
    cout << "Size of stack: " << stack.getCount() << endl;
}

void queueRun(int numTests) {
    Queue queue;
    // loop numTests times
    for (int i = 0; i < numTests; i++) {
        // generate a random number between 0 and 1
        int r = rand() % (101);
        if (r < 51) {
            // insert a random value into the queue
            int value = rand() % (101);
            queue.insert(value);
        } else {
            // remove a value from the queue (if it's not empty)
            if (!queue.isEmpty()){
                queue.remove();
            }
        }
    }
    // prints the queue
    cout << "Queue: " << endl;
    queue.print();
    // print the size of the queue (should be around 20)
    cout << "Size of queue: " << queue.getCount() << endl;
}
int main() {
    srand(time(0));
    int numTests = 0;
    numTests = printMenu();

    // STACKS
    clock_t time1=clock();
    stackRun(numTests);
    // Get end time
    clock_t time2=clock();
    double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Run time for stack: " << run_time << " seconds." << endl;

    cout << "~~~~~~" << endl;

    // QUEUES
    clock_t time3=clock();
    queueRun(numTests);
    clock_t time4=clock();
    double run_time2 = (time4-time3)/(double)CLOCKS_PER_SEC;
    cout << "Run time for queue: " << run_time2 << " seconds." << endl;
    return 0;
}
