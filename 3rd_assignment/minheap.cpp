#include <iostream>
#include <string>

using namespace std;

struct HeapNode{
    int key;
    string value;
    HeapNode(): key(0), value("zero"){};
    HeapNode(int key, string val): key(key), value(val){};
};

class Heap{
    private:
        HeapNode *elements;
        int size;
        int capacity;
    public:
        Heap(int capacity);
        ~Heap();
        bool Enqueue(HeapNode node);
        void ReheapUp(int index);
        HeapNode Dequeue();
        void ReheapDown(int index);
        int getSize();
        void print();
};

bool Heap::Enqueue(HeapNode node){
    if(size == capacity){
        return false;
    }
    else {
        elements[size] = node;
        ReheapUp(size + 1);
        size++;
        return true;
    }
}

HeapNode Heap::Dequeue(){
    if (size == 0){
        return HeapNode(-999, "empty");
    }
    HeapNode temp = HeapNode(elements[0]);
    elements[1] = elements[size];
    size--;
    ReheapDown(1);
    return temp;
}

void Heap::ReheapUp(int index){
    if (index == 1){
        return;
    }
    int parent = index / 2;
    if (elements[index].key > elements[parent].key){
        HeapNode temp = elements[index];
        elements[index] = elements[parent];
        elements[parent] = temp;
        ReheapUp(parent);
    }
    else return;
}

void Heap::ReheapDown(int index){
    int left = index * 2;
    int right = index * 2 + 1;
    int smallest = index;
    if (left <= size && elements[left].key < elements[smallest].key){
        smallest = left;
    }
    if (right <= size && elements[right].key < elements[smallest].key){
        smallest = right;
    }
    if (smallest != index){
        HeapNode temp = elements[index];
        elements[index] = elements[smallest];
        elements[smallest] = temp;
        ReheapDown(smallest);
    }
    else return;
}

void Heap::print(){
    for (int i = 1; i <= size; i++){
        cout << elements[i].value << " ";
    }
    cout << endl;
}

int Heap::getSize(){
    return size;
}

Heap::Heap(int capacity){
    elements = new HeapNode[capacity + 1];
    size = 0;
    this->capacity = capacity;
}

Heap::~Heap(){
    delete [] elements;
}

int main(){
    Heap hello = Heap(10);
    hello.Enqueue(HeapNode(1, "Yo"));
    hello.print();
    hello.Enqueue(HeapNode(2, "what"));
    hello.print();
    hello.Enqueue(HeapNode(7, "doin"));
    hello.print();
    hello.Enqueue(HeapNode(5, "dog"));
    hello.print();
    hello.Enqueue(HeapNode(3, "the"));
    hello.print();
    for (int i = 0; i> 4; i++){
        cout << hello.Dequeue().value << " ";
    }
    return 0;
}