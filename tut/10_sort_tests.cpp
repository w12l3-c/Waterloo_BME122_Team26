// This program tests selection sort and heap sort with arrays of length 10, 100 and 1000

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

// The number of times we will repeat each test
const int NUM_TRIALS = 1000;

// Function declarations
void fillArray(int arr[], int start, int end);

void selectionSort(int arr[], int start, int end);
void heapSort(int arr[], int start, int end);

double timeSelectionSort(int length);
double timeHeapSort(int length);

int main() {
  // To demonstrate that our sort functions work
  int test_arr[10]  = {9, 7, 100, 2, 1, 3, -1, 0, 0, 10};
  int test_arr2[10] = {9, 7, 100, 2, 1, 3, -1, 0, 0, 10};

  cout << "Example array:" << endl;
  for (int i = 0; i < 10; i++)
    cout << test_arr[i] << " ";
  cout << endl << endl;

  cout << "After selection sort:" << endl;
  selectionSort(test_arr, 0, 10);
  for (int i = 0; i < 10; i++)
    cout << test_arr[i] << " ";
  cout << endl << endl;

  cout << "After heap sort:" << endl;
  heapSort(test_arr2, 0, 10);
  for (int i = 0; i < 10; i++)
    cout << test_arr2[i] << " ";
  cout << endl << endl;

  // Tests with arrays of length 10

  cout << "Average sort time (in microseconds) with arrays of length 10" << endl;
  cout << "Selection sort: " << timeSelectionSort(10) << endl;
  cout << "Heap sort: " << timeHeapSort(10) << endl << endl;

  // Tests with arrays of length 100

  cout << "Average sort time (in microseconds) with arrays of length 100" << endl;
  cout << "Selection sort: " << timeSelectionSort(100) << endl;
  cout << "Heap sort: " << timeHeapSort(100) << endl << endl;

  // Tests with arrays of length 1000

  cout << "Average sort time (in microseconds) with arrays of length 1000" << endl;
  cout << "Selection sort: " << timeSelectionSort(1000) << endl;
  cout << "Heap sort: " << timeHeapSort(1000) << endl << endl;
}

// Fills a given array in [start, end) with random values in the range [0, 1000)
void fillArray(int arr[], int start, int end) {
  for (int i = start; i < end; i++)
    arr[i] = rand() % 1000;
}

// Selection sort implementation
void selectionSort(int arr[], int start, int end) {
  int min_ind;
  int tmp;

  // For each position, select the minimum value and swap it into position
  for (int i = start; i < end - 1; i++) {
    // Find minimum location
    min_ind = i;
    for (int j = i + 1; j < end; j++) {
      if (arr[j] < arr[min_ind])
        min_ind = j;
    }

    // Swap minimum into position
    tmp = arr[i];
    arr[i] = arr[min_ind];
    arr[min_ind] = tmp;
  }
}

// Heap sort implementation
// Uses heap implementation from <algorithm> library
void heapSort(int arr[], int start, int end) {
  // Turn the array into a heap
  make_heap(arr + start, arr + end);

  // Sort the heap
  sort_heap(arr + start, arr + end);
}

// Returns the average time to sort an array of a given length using selection sort
double timeSelectionSort(int length) {
  // Create dynamic array
  int* arr = new int[length];
  // Set random seed so we always generate the same random values
  srand(1);

  // Get the starting time
  chrono::steady_clock::time_point begin = chrono::steady_clock::now();

  // Repeats NUM_TRIALS times. Fills the array with random values and then sorts it
  for (int i = 0; i < NUM_TRIALS; i++) {
    fillArray(arr, 0, length);
    selectionSort(arr, 0, length);
  }

  // Get ending time
  chrono::steady_clock::time_point end = chrono::steady_clock::now();

  // Delete dynamic array
  delete[] arr;

  // Return duration divided by NUM_TRIALS to get average time to sort
  return (double) chrono::duration_cast<chrono::microseconds>(end - begin).count() / NUM_TRIALS;
}

// Returns the average time to sort an array of a given length using heap sort
double timeHeapSort(int length) {
  // Create dynamic array
  int* arr = new int[length];
  // Set random seed so we always generate the same random values
  srand(1);

  // Get the starting time
  chrono::steady_clock::time_point begin = chrono::steady_clock::now();

  // Repeats NUM_TRIALS times. Fills the array with random values and then sorts it
  for (int i = 0; i < NUM_TRIALS; i++) {
    fillArray(arr, 0, length);
    heapSort(arr, 0, length);
  }

  // Get ending time
  chrono::steady_clock::time_point end = chrono::steady_clock::now();

  // Delete dynamic array
  delete[] arr;

  // Return duration divided by NUM_TRIALS to get average time to sort
  return (double) chrono::duration_cast<chrono::microseconds>(end - begin).count() / NUM_TRIALS;
}
