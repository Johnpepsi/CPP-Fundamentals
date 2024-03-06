#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << fixed;

    ifstream inData; // declare input stream
    ofstream outData; // declare output stream

    inData.open("ex1_input.txt");
    if (!inData) {
        cout << "Can't open the input file 'ex2_input.txt' successfully." << endl;
        return 1;
    }

    outData.open("ex1_output.txt");
    if (!outData) {
        cout << "Can't open the output file 'ex2_output.txt' successfully." << endl;
        return 2;
    }

    float val1, val2, val3, val4, val5, val6, val7, val8, val9, val10;
    float sum = 0.0f;
    float average = 0.0f;

    // For loops implementation
    for (int i = 0; i < 10; ++i) { // increment
        if (!(inData >> val1)) {
            cout << "Could not read the expected number of floats from the input file 'ex2_input.txt'." << endl;
            return 3;
        }
        sum += val1;
    }

    average = sum / 10.0f; // Calculate the average


    outData << "Now processed file 'ex2_input.txt'" << endl
            << "Sum: " << sum << endl
            << "Average: " << average << endl;

    cout << "Now processed file 'ex2_input.txt'" << endl
         << "Sum: " << sum << endl
         << "Average: " << average << endl;

    inData.close(); // close input file
    outData.close(); // close output file

    return 0;
}
