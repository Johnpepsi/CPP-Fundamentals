#include <iostream>
using namespace std;

float avg(int, int, int, int, int);

int main() {
    int mark1, mark2, mark3, mark4, mark5;

    // prompt user to enter five integer marks
    cout << "Please enter 5 integer marks: ";
    cin >> mark1 >> mark2 >> mark3 >> mark4 >> mark5;

    // average by calling the avg function
    float average = avg(mark1, mark2, mark3, mark4, mark5);
    cout << "The average of those marks is: " << average << endl;

    return 0;
}

// avg function
float avg(int m1, int m2, int m3, int m4, int m5) {
    return (m1 + m2 + m3 + m4 + m5) / 5.0; 
}