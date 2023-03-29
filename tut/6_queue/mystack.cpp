#include "mystack.h"

struct MyStack::Node {
  char data;
  Node* next;

  // A constructor for the Node. Not required but makes things a bit cleaner
  Node(char new_data, Node* new_next) : data(new_data), next(new_next) {
    // Intentionally left empty
  };
};

MyStack::~MyStack() {
  while (!empty())
    pop();
}

void MyStack::pop() {
  Node* temp = head;
  head = head->next;
  delete temp;
}

void MyStack::push(char value) {
  head = new Node(value, head);
}

char MyStack::top() {
  return head->data;
}

bool MyStack::empty() {
  return (head == nullptr);
}
