#include <iostream>
#include <queue>
#include <string>

using namespace std;

class HeapNode{
    private:
    
    int key;
    string text;
    
    public:

    HeapNode(): key(0), text(""){};
    HeapNode(int a): key(a), text(""){};
    HeapNode(int a, string b): key(a), text(b){};
    int getKey(){
        return key;
    }
    string getText(){
        return text;
    }
};

class Heap {
    private:
        HeapNode *elements;
        int size;
        int capacity;


    public:
        Heap(int cap);
        ~Heap();
        bool Enqueue(HeapNode item);
        void ReheapUp(int index);
        HeapNode Dequeue(); 
        void ReheapDown(int index);
        int getSize();
        void printAll();
};

Heap::Heap(int cap){
    capacity = cap;
    size = 0;
    elements = new HeapNode[capacity];
}

Heap::~Heap(){
    delete[] elements;
    elements = nullptr;
}

bool Heap::Enqueue(HeapNode item){
    if (size == capacity)
        return false;
    else {
        elements[size+1] = item;
        ReheapUp(size+1);
        size++;
        return true;
    }
}

void Heap::ReheapUp(int index){
    if (index==1)
        return;
    int parent = index/2;
    if (elements[parent].getKey() > elements[index].getKey()){
        HeapNode temp = elements[parent];
        elements[parent] = elements[index];
        elements[index] = temp;
        ReheapUp(parent);
    }
    else
    return;
    
}

HeapNode Heap::Dequeue(){
    if (size == 0)
        return HeapNode(-9999, "EMPTY_HEAP_RETURN");
    HeapNode temp = HeapNode(elements[1]);
    elements[1] = elements[size];
    size--;
    ReheapDown(1);
    return temp;
}


void Heap::ReheapDown(int index){
    if (2*index>size) return;

    int chosenChild;

    if (2*index == size) chosenChild = size;
    else {
        int leftChild = 2*index;
        int rightChild = 2*index+1;

        if (elements[leftChild].getKey() <= elements[rightChild].getKey()) 
            chosenChild = leftChild;
        else
            chosenChild = rightChild;
    }

    if (elements[chosenChild].getKey() < elements[index].getKey()) {
        HeapNode temp = elements[chosenChild];
        elements[chosenChild] = elements[index];
        elements[index] = temp;

        ReheapDown(chosenChild);
    }
    else return;
}

int Heap::getSize(){
    return size;
}

void Heap::printAll(){
    for (int i = 1; i < size+1; i++){
        cout << elements[i].getKey() << endl;
    }
}

int main(){
    // testing
    Heap x(10);
    x.Enqueue(HeapNode(11));
    x.Enqueue(HeapNode(7));
    x.Enqueue(HeapNode(3));
    x.Enqueue(HeapNode(31));
    x.Enqueue(HeapNode(5));
    x.Enqueue(HeapNode(1));
    x.Enqueue(HeapNode(20));
    x.Dequeue();
    x.Dequeue();
    x.Dequeue();
    x.printAll();
    return 0;
}

