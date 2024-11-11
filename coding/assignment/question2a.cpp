#include <iostream>
using namespace std;

int main() {
    int number;

    while (true) {
        cout << "Enter a positive integer (or a non-positive integer to exit): ";
        cin >> number;

        // check if the number is not positive (0 or negative)
        if (number <= 0) {
            break; // will exit the loop if the number is non-positive
        }
        if (number > 100) {
          cout << number << " "; // prints with a space
        }
    }

      cout << endl;
    return 0;
}
