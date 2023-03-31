#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Node class
class HeapNode{
    private:
    
    // Node key and optional node message
    int key;
    string text;
    
    public:

    // 3 Constructors: default, key only, and key and message
    HeapNode(): key(0), text(""){};
    HeapNode(int a): key(a), text(""){};
    HeapNode(int a, string b): key(a), text(b){};

    // Get method for key
    int getKey(){
        return key;
    }

    // Get method for text
    string getText(){
        return text;
    }
};

class Heap {

    // Nodes, num of nodes, and capacity stores
    private:
        HeapNode *elements;
        int size;
        int capacity;


    public:
        // Constructor, destructor and methods declared
        Heap(int cap);
        ~Heap();
        bool Enqueue(HeapNode item);
        void ReheapUp(int index);
        HeapNode Dequeue(); 
        void ReheapDown(int index);
        int getSize();
        void printAll();
};

// Constructor, initializing capacity and elements array, accordingly
Heap::Heap(int cap){
    capacity = cap;
    size = 0;
    elements = new HeapNode[capacity];
}


// Element array memory is freed via destructor
Heap::~Heap(){
    delete[] elements;
    elements = nullptr;
}

// Add node
bool Heap::Enqueue(HeapNode item){
    
    // Do not add if maximum capacity is reached
    if (size == capacity)
        return false;
    
    // Append node to end of array; rearrange and increase size
    else {
        elements[size+1] = item;
        ReheapUp(size+1);
        size++;
        return true;
    }
}


// Method for rearrangement after enqueueing
void Heap::ReheapUp(int index){
    // If first node, no changes
    if (index==1)
        return;

    // Else find parent node and change order if required; keep recursively rearranging with parents until root is reached
    int parent = index/2;
    if (elements[parent].getKey() > elements[index].getKey()){
        HeapNode temp = elements[parent];
        elements[parent] = elements[index];
        elements[index] = temp;
        ReheapUp(parent);
    }
    // Stop when parent is smaller than child
    else
    return;
    
}

// Remove root node
HeapNode Heap::Dequeue(){
    // Return error node if array empty
    if (size == 0)
        return HeapNode(-9999, "EMPTY_HEAP_RETURN");
    
    // Replace root node with last node; decrease size; reheap down tree
    HeapNode temp = HeapNode(elements[1]);
    elements[1] = elements[size];
    size--;
    ReheapDown(1);
    return temp;
}


void Heap::ReheapDown(int index){
    // Stop when both children exceed capacity (i.e. end of tree)
    if (2*index>size) return;

    // Variable to chose child
    int chosenChild;
    
    // Special case where left child is last element - only one child
    if (2*index == size) chosenChild = size;
    
    // 2 Children
    else {
        int leftChild = 2*index;
        int rightChild = 2*index+1;

        // Choose child with smaller value
        if (elements[leftChild].getKey() <= elements[rightChild].getKey()) 
            chosenChild = leftChild;
        else
            chosenChild = rightChild;
    }

    // Swap parent and child if necessary
    if (elements[chosenChild].getKey() < elements[index].getKey()) {
        HeapNode temp = elements[chosenChild];
        elements[chosenChild] = elements[index];
        elements[index] = temp;

    // Loop down recursively
        ReheapDown(chosenChild);
    }

    // Stop when nodes are in order
    else return;
}

// Access keys
int Heap::getSize(){
    return size;
}

// Print node keys from 1 to size
void Heap::printAll(){
    for (int i = 1; i < size+1; i++){
        cout << elements[i].getKey() << " ";
    }
}

// Testing
int main(){
    
    // Define heap x with 10 capacity
    Heap x(10);

    // Add 11, 7, 3, 31, 5, 1, 20
    x.Enqueue(HeapNode(11));
    x.Enqueue(HeapNode(7));
    x.Enqueue(HeapNode(3));
    x.Enqueue(HeapNode(31));
    x.Enqueue(HeapNode(5));
    x.Enqueue(HeapNode(1));
    x.Enqueue(HeapNode(20));

    // Remove root node 3 times; smallest 3 values should be removed (i.e. 1, 3, 5)
    x.Dequeue();
    x.Dequeue();
    x.Dequeue();

    // Should print 7 11 20 31, as expected from minHeap
    x.printAll();

    return 0;
}

