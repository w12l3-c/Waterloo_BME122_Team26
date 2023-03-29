// BME 122: Tutorial 5
// Stack examples
// 2023-02-15

#include "mystack.h"
#include <iostream>
#include <string>

// Input: A string containing only "(", ")", "[" and "]"
// Output: True if the bracket is valid
bool validBrackets(string input);

int main() {
  // Test the stack implementation
  MyStack stack;

  stack.push('a');
  stack.push('b');
  stack.push('c');

  // If the stack implementation is correct we will see c b a
  while (!stack.empty()) {
    cout << stack.top() << " ";
    stack.pop();
  }

  cout << endl << endl;

  // Test validBrackets
  
  // Test cases
  string brackets0 = "[]([]())"; // Valid
  string brackets1 = "[][[]())"; // Invalid
  string brackets2 = "()()[()()])[[]]"; // Invalid
  string brackets3 = ""; // Valid
  string brackets4 = "("; // Invalid

  cout << "Is \"" << brackets0 << "\" valid? " << validBrackets(brackets0) << endl;
  cout << "Is \"" << brackets1 << "\" valid? " << validBrackets(brackets1) << endl;
  cout << "Is \"" << brackets2 << "\" valid? " << validBrackets(brackets2) << endl;
  cout << "Is \"" << brackets3 << "\" valid? " << validBrackets(brackets3) << endl;
  cout << "Is \"" << brackets4 << "\" valid? " << validBrackets(brackets4) << endl;

  return 0;
}

bool validBrackets(string input) {
  MyStack stack;

  // For each character
  for (char x : input) {
    // If we open a bracket, add it to the stack
    if (x == '(' || x == '[') {
      stack.push(x);
    // If we are closing a bracket:
    } else { 
      // If the stack is empty, we don't have a match -> return false
      if (stack.empty()) 
        return false;
      // If we have a matching bracket, remove it from the stack so we don't match it again
      else if (stack.top() == '(' && x == ')' || stack.top() == '[' && x == ']')
        stack.pop();
      // If there is a bracket in the stack but it doesn't match -> return false
      else
        return false;
    }
  }
  
  // If the stack is empty, all brackets matched -> return true
  // If the stack isn't empty, we have unmatched brackets -> return false
  return stack.empty();
}
