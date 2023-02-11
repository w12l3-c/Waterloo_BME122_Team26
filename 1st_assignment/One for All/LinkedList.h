#ifndef LINKED_LINKED_CLASS
#define LINKED_LINKED_CLASS

//Struct for Node
struct Node{
    
    //Int Variable to hold data
    int data;

    //Node pointer to hold the address for next node
    Node* next;

};


//Class header for Linked List
class LinkedList{
    private:
         //Stores the head pointer
        Node* head;  

    public:
        //Contructors and Destructors
        LinkedList();
        LinkedList(int num);
        ~LinkedList();
        
        void print(); //Prints the list
        void insert(int num); //Inserts a node at the end of the list
        Node* getTail(Node* node); //Recursive function to get end of linked list to insert
        void clear(); //Clears the list
};

#endif