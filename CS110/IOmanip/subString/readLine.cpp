// Program ex2_readline.cpp demonstrates how to read a line of text from a file

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	string str1, str2, str3, str4;
	ifstream inData;
	ofstream outData;

	inData.open("input.txt");

	if(!inData){
		cout << "Error: Unable to open input file 'input.txt'" << endl;
	return 1;
	}

	outData.open("output.txt");

	if(!outData){
		cout << "Error: Unable to open output file 'output.txt" << endl;
	return 2;
	}
	
	getline(inData, str1);
	getline(inData, str2);
	getline(inData, str3);
	getline(inData, str4);
	
	outData << str4 << endl;
	outData << str3 << endl;
	outData << str2 << endl;
	outData << str1 << endl;

	inData.close();
	outData.close();

	return 0;
}