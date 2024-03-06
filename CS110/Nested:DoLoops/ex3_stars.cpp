#include <iostream>
using namespace std;

int main() {
    int numStars; // var for the stars
    cout << "How many stars on the first line? ";
    cin >> numStars;

    // Outer loop for each line
    for (int i = numStars; i > 0; i--) {
        // Inner loop for printing stars in each line
        for (int k = 0; k < i; k++) {
            cout << "*";
        }
        // Newline after each row of stars
        cout << endl;
    }

    return 0;
}
