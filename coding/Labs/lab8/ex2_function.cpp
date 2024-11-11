// Program functionP prints a triangle of stars.
// For example:
//     *****
//     ****
//     ***
//     **
//     *

#include <iostream>
using namespace std;

// Function prototype
void printStars(int num);

int main()
{
    int numOfStars;

    cout << "Enter the number of stars in the first line: " << endl;
    cin >> numOfStars;

    while (numOfStars > 0)
    {
        printStars(numOfStars); // Invoke function to print stars
        numOfStars--; // Decrease the number of stars for the next line
    }

    return 0;
}

//****************************************************************************

void printStars(int num)
{
    for (int i = 0; i < num; i++) {
        cout << "*";
    }
    cout << endl; // Move to the next line after printing stars
}
