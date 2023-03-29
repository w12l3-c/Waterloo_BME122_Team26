// BME 122: Tutorial 6
// Queue example
// 2023-02-29

#include "mystack.h"
#include <iostream>
#include <string>

class MyQueue {
    
private:
    struct Node {
        char data;
        Node* next;

        // A constructor for the Node. Not required but makes things a bit cleaner
        Node(char new_data, Node* new_next) : data(new_data), next(new_next) {
            // Intentionally left empty
        };
    };
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    
    ~MyQueue() {
        while (!empty())
            dequeue();
    }

    // // Version of enqueue that uses tail pointer
    // void enqueue(char value) {
    //     if (head == nullptr) {
    //         head = new Node(value, nullptr);
    //         tail = head;
    //     }
    //     else {
    //         tail->next = new Node(value, nullptr);
    //         tail = tail->next;
    //     }
    // }

    // Version of enqueue that doesn't need to store tail pointer
    void enqueue(char value) {
        if (head == nullptr) {
            head = new Node(value, nullptr);
        }
        else {
            Node* temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(value, nullptr);
        }
    }

    char dequeue() {
        Node* temp = head;
        char value = head->data;
        head = head->next;
        delete temp;
        return value;
    }

    char peek() {
        return head->data;
    }

    bool empty() {
        return (head == nullptr);
    }
};

int main() {
    // Test the queue implementation
    MyQueue queue;
    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');
  
    // If the queue implementation is correct we will see a b c
    while (!queue.empty()) {
        cout << queue.peek() << " ";
        queue.dequeue();
    }
    cout << endl;

    queue.enqueue('a');
    cout << queue.dequeue() << endl;
    queue.enqueue('b');
    queue.enqueue('c');
    queue.enqueue('d');
    cout << queue.dequeue() << endl;
    queue.enqueue('e');

    // If the queue implementation is correct we will see c d e
    while (!queue.empty()) {
        cout << queue.peek() << " ";
        queue.dequeue();
    }
    cout << endl;
  
    return 0;
}
