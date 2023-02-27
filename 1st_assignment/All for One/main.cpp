/**
 * BME 122 2022
 * Assignment 1
 * Group 26
 * Aaron Jumarang,  Wallace Lee, John Matti, Aric Quan
*/

#include <iostream>
using namespace std;

////////////////////////////////
///////     STRUCT       ///////
////////////////////////////////

//Struct for Node
struct Node{
    
    //Int Variable to hold data
    int data;

    //Node pointer to hold the address for next node
    Node* next;

};


////////////////////////////////
///   CLASS DECLARATION      ///
////////////////////////////////

//Class header for Linked List
class LinkedList{
    private:
         //Stores the head pointer
        Node* head;  

    public:
        //Contructors and Destructors
        LinkedList();
        ~LinkedList();
        
        void print(); //Prints the list
        void insert(int num); //Inserts a node at the end of the list
        Node* getTail(Node* node); //Recursive function to get end of linked list to insert
        void clear(); //Clears the list
};




////////////////////////////////
///   CLASS DEFINITIONS      ///
////////////////////////////////

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    //Default list will have no elements
    head = NULL;
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
        cout << it->data << " ";

        //Goes to the next node
        it = it->next;
    }
    cout << endl;
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

    //Checks if the list is empty. If so, create a head
    if(head == NULL){

        //Initialize the head
        head = new Node();
        head->data = num;
        head->next = NULL;

        //Ends the function early
        return;
    }

    /*If the list is not empty*/

    //Calls recursive function to get tail pointer
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

    //Check if list is cleared already
    if (head == NULL){
        return;
    }

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




////////////////////////////////
///////     TEST       /////////
////////////////////////////////
int main() {

    //Creates a new linked list
    LinkedList list;

    //Loops until user wants to leave
    while(true){
        
        //Prints the options
        cout << "Actions: " << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Print new node" << endl;
        cout << "3. Clear linked list" << endl;
        cout << "4. Exit" << endl;
        cout << "What actions would you like? ";

        //Gets user options
        int input;
        cin >> input;

        //Checks if the user input is invalid
        if (cin.fail()) {

            //Clears inputs
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "\n\nInvalid Input" << endl;
        }

        //If the user input is good
        else {

            /*If the user chose to insert new node*/
            if(input == 1){

                //Loops until a valid integer is entered
                while(true){

                    //Asks user for number
                    cout << "Enter an integer: ";
                    int newData;
                    cin >> newData;

                    //Checks if the input is valid
                    if (cin.fail()) {

                        //Clears input
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "\nInvalid Input" << endl;
                    }

                    //If user input is valid
                    else{

                        //Inserts input to list
                        list.insert(newData);
                        cout << "\n\n" << endl;
                        break;
                    }
                }
            }

            /*If the user wants to print the list*/
            else if (input == 2){
                cout << "\n\nList is:" << endl;

                //Prints list
                list.print();
            }

            /*If the user wants to clear the list*/
            else if (input == 3){
                cout << endl << "List Cleared" << endl;

                //Clears list
                list.clear();
            }

            /*Ends the program*/
            else if (input == 4){

                //Exits big loop
                break;
            }

            /*Tells user they entered a bad input*/
            else {
                cout << "\n\nInvalid Input" << endl;
            }
        }
    }

    return 0;
}