/************************************************************
 *
 *       FileName: caseswitch.cpp
 *       Author:   John Palaganas
 *       Purpose:  Demonstrate how to use Switch Statement.
 *
 **************************************************************/
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
            cout << "Great work. " << endl;
            break;
        // Case for 'B' that prints "Good work."
        case 'B':
            cout << "Good work." << endl;
            break;
        case 'C':
            cout << "Passing work. " << endl;
            break;
        case 'D':
            cout << "Unsatisfactory work. " << endl;
            break;
        case 'F':
            cout << "See your instructor." << endl;
            break;

        // Default case for invalid grades
        default:
            cout << grade << " is not a legal grade." << endl;
            break;
        } // end of switch statement

    } // end of for loop

    return 0;

} // end program
