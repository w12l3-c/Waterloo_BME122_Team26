// BME 122: Tutorial 6
// Queue example
// 2023-02-29

#include "mystack.h"
#include <iostream>
#include <string>

class MyQueue {
private:
    MyStack stack1, stack2;

public:    
    void enqueue(char x) {
        stack1.push(x);
    }
    
    char dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        char removed_val = stack2.top();
        stack2.pop();
        return removed_val;
    }
    
    char peek() {
        if (stack2.empty()) {
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    ~MyQueue() {
        while (!empty())
            dequeue();
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