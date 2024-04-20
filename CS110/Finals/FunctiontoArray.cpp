#include <iostream>

using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the average of values in an array
double findAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

// Function to find the largest value in an array
int findLargest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function to find the smallest value in an array
int findSmallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

// Function to reverse the order of elements in an array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Function to swap values at specific indexes in an array
void swapValues(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};

    // Print the original array
    cout << "Original array:" << endl;
    printArray(arr, size);

    // Swapping values at specific indexes
    swapValues(arr, 1, 3);

    // Printing the modified array
    cout << "Array after swapping values at indexes 1 and 3:" << endl;
    printArray(arr, size);

    // Finding and printing the average of values in the array
    cout << "Average value: " << findAverage(arr, size) << endl;

    // Finding and printing the largest value in the array
    cout << "Largest value: " << findLargest(arr, size) << endl;

    // Finding and printing the smallest value in the array
    cout << "Smallest value: " << findSmallest(arr, size) << endl;

    // Reversing the order of elements in the array
    reverseArray(arr, size);

    // Printing the reversed array
    cout << "Array after reversing:" << endl;
    printArray(arr, size);

    return 0;
}
