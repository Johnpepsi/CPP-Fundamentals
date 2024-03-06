#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str1, str2, str3, str4;      // declares 4 variables
    ifstream inData;                    // declares input stream
    ofstream outData;                   // declares output stream

    inData.open("ex2_input.txt");
    // binds program variable inData to the input file "ex2_input.txt"

    outData.open("ex2_output.txt");
     // binds program variable outData to the output file "ex2_output.txt"

    // input 4 lines
    getline(inData,str1);
    getline(inData,str2);
    getline(inData,str3);
    getline(inData,str4);

    // output 4 lines
    outData  << str4  << endl;
    outData  << str3  << endl;
    outData  << str2  << endl;
    outData  << str1  << endl;  // outputs 4 lines

    inData.close();
    outData.close();

    return 0;
}
