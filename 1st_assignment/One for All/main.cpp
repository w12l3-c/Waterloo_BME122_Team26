#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {

    /*
    Test 1
    */

    //Default constructor
    LinkedList newList;

    //Inserts a bunch of numbers
    newList.insert(10);
    newList.insert(11);
    newList.insert(69);
    newList.insert(420);
    newList.insert(1738);

    //Prints the list
    newList.print();

    //Clears the list
    newList.clear();

    //Shows that the list is empty
    newList.print();


    /*
    Test 2
    */

    //Creates a new linked list with the head equal to 10
    LinkedList newerList(10);

    //Inserts numbers
    newerList.insert(100);
    newerList.insert(1000);

    //Prints numbers
    newerList.print();


    return 0;
}