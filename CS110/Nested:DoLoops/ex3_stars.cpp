/*************************************************
 * Student Name: John Palaganas
 * Student Number: 200480405
 * Replit User Name: <~~jpl653~~<<
 * Acitvity: Lab 7 Exercise 1 - 3
 * Program Name: ex3_stars.cpp
 * Last Modified: March 05 2024
 * Learning: do neste loops - stars 
 //Please complete this exercise using the description in the lab notes
 *************************************************/

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
