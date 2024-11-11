/***
Purpose:  Similar to FloydsTriangle but decrement
**/
#include <iostream>
using namespace std;

int main() {
    int stars;

    cout << "How many stars on the first line? ";
    cin >> stars;

    // Outer loop for each line
    for (int i = stars; i > 0; i--) {
        // Inner loop to print stars in each line
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;  // Move to the next line after each row
    }

    return 0;
}
