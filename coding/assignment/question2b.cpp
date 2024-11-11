#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int k = 1; // this starts counting from 1
    int total = 0; // tnitialize total to 0

    // while loop to compute the sum of cubes
    while (k <= n) {
        total += k * k * k; // adds the cube of k to total
        k++;
    }

    cout << "The sum of the cubes of the first " << n << " counting numbers is: " << total << endl;

    return 0;
}