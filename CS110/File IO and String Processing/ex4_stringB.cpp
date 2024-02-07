/*************************************************
 * Student Name: John Palaganas
 * Student Number: 200480405
 * Assignment Number: CS 110 Lab 4 exercise 4
**************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << fixed;

    string originalString;
    originalString = "And now for something completely different";

    cout << endl;

    cout << "1. Display the content of originalString "
         << originalString << endl;

    cout << endl;

    cout << "2. Display the length of originalString "
         << originalString.length() << endl;

    cout << endl;

    string srch = "complete";

    int pos = originalString.find(srch);
    cout << "3. Display the position of completely "
         << endl << pos << endl;

    string newString = originalString.substr(0, 21);

    cout << endl;
    
    cout << "4. Output newString " << endl << newString << endl;
    cout << endl;
    
    newString += " "+ originalString.substr(33);
    
    cout << "5. Add this substring to newString and display " << endl
        << newString << endl;

return 0;

}