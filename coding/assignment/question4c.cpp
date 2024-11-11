#include <iostream>
using namespace std;

int main() {
    int rows = 5; // Number of rows in the pattern

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            // Print 1 if the sum of row and column indices is odd, else print 0
            if ((i + j) % 2 == 0) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
