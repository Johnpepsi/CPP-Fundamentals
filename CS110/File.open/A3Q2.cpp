/*************************************************
 * ------ Problem Statement -----
 * Write a program that prompts the user to enter a hexadecimal digit
 * or an integer between 0-15 and display its corresponding decimal number
 * or hex decimal number units.
 * The program must first ask the user to choose
 * what kind of conversion and then ask the user to enter
 * number to convert.
 *************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    char conversionType;
    string number;
    cout << "\n\n\n\n\nEnter 'H' to convert Hexadecimal to decimal or 'D' to convert Decimal to hexadecimal: ";
    cin >> conversionType;
    cout << "Enter the number to convert: ";
    cin >> number;

    switch(conversionType) {
        case 'h':
        case 'H':
            cout << stoi(number, nullptr, 16);
            break;
        case 'd':
        case 'D':
            {
                stringstream ss;
                ss << hex << stoi(number);
                cout << ss.str();
                ss.str(""); // For clearing stringstream
                ss.clear(); // Resetting user flags
            }
            break;
        default:
            cout << "Invalid conversion type.";
            break;
    }
    return 0;
}
