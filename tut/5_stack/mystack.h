#ifndef MYSTACK_H
#define MYSTACK_H

using namespace std;

class MyStack {
  public:
    ~MyStack();

    void pop();
    void push(char value);
    char top();
    bool empty();

  private:
    struct Node;

    Node* head = nullptr;
};

#endif // MYSTACK_H
