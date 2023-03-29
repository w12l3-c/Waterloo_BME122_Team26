// BME 122: Tutorial 3
// Power Of Example
// 2023-02-01

#include <iostream>

using namespace std;

bool powerOf(int y, int x); // Returns true if y is a power of x

int main() {
  // Test cases:

  // X and Y are positive
  cout << "Is 4 a power of 2? " << powerOf(4, 2) << endl; // true
  cout << "Is 4 a power of 3? " << powerOf(4, 3) << endl; // false

  // X is negative
  cout << "Is 4 a power of -2? " << powerOf(4, -2) << endl; // true
  cout << "Is 8 a power of -2? " << powerOf(8, -2) << endl; // false

  // Y is negative
  cout << "Is -4 a power of 2? " << powerOf(-4, 2) << endl; // false

  // X and Y are negative
  cout << "Is -8 a power of -2? " << powerOf(-8, -2) << endl; // true
  cout << "Is -4 a power of -2? " << powerOf(-4, -2) << endl; // false

  // X is 0
  cout << "Is 4 a power of 0? " << powerOf(4, 0) << endl; // false
  cout << "Is 1 a power of 0? " << powerOf(1, 0) << endl; // true
  cout << "Is 0 a power of 0? " << powerOf(0, 0) << endl; // true

  // Y is 0
  cout << "Is 0 a power of 2? " << powerOf(0, 2) << endl; // false
}

bool powerOf(int y, int x) {
  // Our algorithm doesn't work when x = 0, so we handle that case seperately
  if (x == 0)
    return y == 0 || y == 1;

  // Base cases
  if (y == 0)
    return false;
  if (y == 1)
    return true;
  if (y % x != 0)
    return false;

  return powerOf(y / x, x); // Recursive call
}
