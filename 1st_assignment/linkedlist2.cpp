#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
        // contructors and destructors
        LinkedList();
        LinkedList(int num1);
        LinkedList(int num1, int num2);
        ~LinkedList();

        Node* head;
        
        void print(); // print all the data of every node in the linkedlist
        void append(int num, Node* curr); // append a new node to the end of the linkedlist
};

LinkedList::LinkedList(){
    // default head linked list with data = 0
    head = new Node();
    head->next = NULL;
    head->data = 0;
}

LinkedList::LinkedList(int num1){
    // inistalize a node in linked list with num1
    head = new Node();
    head->next = NULL;
    head->data = num1;
}

LinkedList::LinkedList(int num1, int num2){
    // create a second node with the num2
    Node* curr = new Node();
    curr->data = num2;
    curr->next = NULL;
    // create the first node and point next to the second node
    head = new Node();
    head->next = curr;
    head->data = num1;
}

LinkedList::~LinkedList(){
    // create a linked list that points to the original linked list
    Node* curr = this->head;
    // loop through the linked list
    while (curr->next != NULL){
        // create a dummy linkedlist to hold current node
        Node* temp = curr;
        // the current linkedlist advance to next node
        curr = curr->next;
        // delete the dummy node
        temp = NULL;
        delete temp;
    }
    // delete the linkedlist object that was used to loop through
    curr = NULL;
    delete curr;
}

void LinkedList::print(){
    // create a linked list that points to the original linked list
    Node* curr = this->head;
    // loop through the linked list
    while (curr->next != NULL){
        // print the data within the node of the linkedlist
        cout << curr->data << ' ';
        // advance the linkedlist into the next node
        curr = curr->next;
    }
    // print out the data in the last node
    cout << curr->data << endl;
}

void LinkedList::append(int add, Node* curr){
    // if the linkedlist is emtpy return void
    if (curr == NULL){
        return;
    }
    // if the linkedlist next pointer doesn't point to NULL (next is pointing to another node)
    if (curr->next != NULL){
        
        // return the function as a recursive approach
        return append(add, curr->next);
    }
    // until it reaches the end of the linked list
    else{
        // create a node
        Node* temp = new Node();
        temp->data = add;
        temp->next = NULL;
        // point the next of the current node (last one) to the new node with add as data value
        curr->next = temp;
        return;
    }
}

int main(int argc, char** argv){
    // create a linked list
    
    LinkedList link = LinkedList();
    
    // iteratively add 10 values to the end of linked list
    for (int i = 1; i <= 10; i++){
        link.append(i, link.head);
    }
    // append another value to the end of the linked list
    link.append(15, link.head);
    // print out all the data values in each node of the linked list
    link.print();
    return 0;
}