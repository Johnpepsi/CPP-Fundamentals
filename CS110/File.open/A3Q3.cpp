/******* ------ Problem Statement -----
 * Write a C++ program that reads in from a file that contains full names of employees 
 * of ABC Company. The file is formatted in the following or hex decimal number units.
  ******************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("employees.txt"); // Assuming the file is named employees.txt
    string line;

    if (!file.is_open()) {
        cerr << "Could not open the file." << endl; // Prompt if used a wrong .txt file
        return 1;
    }


    while (getline(file, line)) {
        istringstream iss(line);
        string lastName, firstName, middleName;
        string fullName;

        // Read the names from the line
        iss >> firstName >> middleName >> lastName;

        // Combine names to form full name as per the specified format
        if (middleName.length() == 1) { // Middle name is actually an initial
            fullName = lastName + ", " + firstName + " " + middleName + ".";
        } else {
            fullName = lastName + ", " + firstName + " " + middleName.substr(0, 1) + ".";
        }

        // Output the formatted full name
        cout << fullName << endl;
        cout << "------------" << endl;
        cout << "First name: " << firstName << " (" << firstName.size() << ")" << endl;
        cout << "Middle name: " << middleName << " (" << middleName.size() << ")" << endl;
        cout << "Last name: " << lastName << " (" << lastName.size() << ")" << endl;
        cout << "------------" << endl << endl;
    }

    file.close();
    return 0;
}
