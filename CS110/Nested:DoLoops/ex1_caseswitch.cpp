#include <iostream>
using namespace std;
int main()
{
    char grade;

    // Fill in this for loop so it will repeat six times
    for (int i = 0; i < 6; i++)
    {
        cout << "Please enter a character grade (A, B, C, D, or F): ";
        cin >> grade;

        switch (grade)
        {
        case 'A':
            cout << "Great work." << endl;
            break;

        // Add a case for 'B' that prints "Good work."
        case 'B':
            cout << "Good work." << endl;
            break;

        case 'C':
            cout << "Passing work." << endl;
            break;
        case 'D':
        case 'F':
            cout << "Unsatisfactory work." << endl;
            cout << "See your instructor." << endl;
            break;

        // Add a default that prints
        // grade << " is not a legal grade."
        default:
            cout << grade << " is not a legal grade." << endl;
            break;

        } //end of switch statement

    } //end of for loop

    return 0;

}// end program
