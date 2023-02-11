#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    //Default list will have no elements
    head = NULL;
}


/**
 * A constructor that accepts a number for the initial head
 * @param num : Initial value of the linked list head
 */
LinkedList::LinkedList(int num) {
    //Initialize the first node with value of num
    head = new Node();
    head->data = num;
    head->next = NULL;
}


/**
 * A destructor that deletes the linked list
 */
LinkedList::~LinkedList() {
    //Clears the list
    clear();
}


/**
 * Prints out the elements of the linked list
 */
void LinkedList::print() {

    //Checks if the linked list is empty
    if (head == NULL){
        cout << "List is empty" << endl;

        //Ends the function early
        return;
    }

    /*If the list is not empty, it will iterate through each node*/

    //Node pointer to act as an iterator
    Node * it = head;
    
    //Loops until it reaches the tail
    while(it != NULL) {

        //Prints out the value of the node
        cout << it->data << endl;

        //Goes to the next node
        it = it->next;
    }
}


/**
 * Recursive function to get the tail of the linked list
 * Calls this function until it reaches the tail of the node
 * @return the node of the tail
 */
Node* LinkedList::getTail(Node* node) {

    //Base case: If the node's next pointer is null, it is the tail and returns the node pointer
    if(node->next == NULL){
        return node;
    }

    //Recursive call to next node
    return getTail(node->next);
}


/**
 * Function to insert a number to the end of the list
 * @param num The value of the new node
 */
void LinkedList::insert(int num) {

    //Checks if the list is empty
    if(head == NULL){

        //Initialize the list
        head = new Node();
        head->data = num;
        head->next = NULL;

        //Ends the function early
        return;
    }

    /*If the list is not empty*/

    //Gets the pointer to the tail
    Node * tail = getTail(head);

    //Inserts a new node to the tail
    tail->next = new Node();
    tail = tail->next;

    //Set the new node's values
    tail->data = num;
    tail->next = NULL;
}


/**
 * Function to clear the list
 */
void LinkedList::clear() {

    //Place holder pointer to hold the address of previous node
    Node * prev;

    //Loops until it reaches the tail
    while(head -> next != NULL) {

        //The head will become the previous node
        prev = head;

        //The new head will be the next node
        head = head -> next;

        //Deletes the previous node
        delete prev;
    }

    //Sets the head to null to indicate it is empty
    head = NULL;
}
