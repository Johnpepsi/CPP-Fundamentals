#include <iostream>
#include <limits> // Include for numeric_limits

using namespace std;

// Function prototypes
void enterNumbers(int arr[], int size);
void printArray(const int arr[], int size);
int maxValue(const int arr[], int size);

int main() {
    const int size = 10;
    int numbers[size];
    
    // User enters numbers
    enterNumbers(numbers, size);
    
    // Array prints
    printArray(numbers, size);
    
    // Find and print the maximum value in the array
    const int findMax = maxValue(numbers, size);
    cout << "The maximum value in the array is: " << findMax << endl;
    
    return 0;
}

// Function that enter numbers into array
void enterNumbers(int arr[], int size) {
    cout << "Enter 10 numbers here: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

// Function that prints array elements
void printArray(const int arr[], int size) {
    cout << "Array elements are: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function that finds the max value
int maxValue(const int arr[], int size) {
    int max = numeric_limits<int>::min(); // Initialize max with the smallest possible integer
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
