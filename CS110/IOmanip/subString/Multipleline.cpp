#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() { // Corrected the function name to "main"

    ifstream infile1("input1.txt"); // input file
    ifstream infile2("input2.txt");
    ofstream outfile("outfile.txt"); // output file

    int num1, num2;

    while (!infile1.eof()) {

        infile1 >> num1;
        infile2 >> num2;

        outfile << num1 << num2;
    }

    // close the file
    infile1.close();
    infile2.close();
    outfile.close();

    return 0;
}