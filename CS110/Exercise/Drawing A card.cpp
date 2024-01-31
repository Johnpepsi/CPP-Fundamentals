/*
file name: drawcard.cpp
author: Devon Blewett
purpose: This program generates a random number between 1 and 13 and places it in a box to represent a card

Written for the Open Textbooks program
*/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main() {
    // draw a card between 1 and 13
    srand(time(NULL));
    int card = rand() % 13 + 1;

    // create the top line of dashes
    cout << setfill('-') << setw(7) << "" << endl;
    // create 2nd row, empty
    cout << "|" << setfill(' ') << setw(6) << "|" << endl;
    // put number in third row, left aligned to prevent card from breaking if double digit card drawn
    cout << "|  " << setw(2) << left << card  << " |" << endl;
    // create 4th row, reset align to right
    cout << "|" << right << setw(6) << "|" << endl;
    // create bottom row of dashes
    cout << setfill('-') << setw(7) << "" << endl;

    return 0;
}
