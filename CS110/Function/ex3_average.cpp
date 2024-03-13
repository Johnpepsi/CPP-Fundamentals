#include <iostream>
using namespace std;

// Function double average
double avg(int, int, int, int, int);

int main() {
  int mark1, mark2, mark3, mark4, mark5;

  // Prompt and read five integer marks
  cout << "Please enter 5 integer marks: ";
  cin >> mark1 >> mark2 >> mark3 >> mark4 >> mark5;

  // Calculates the average and printed
  double average = avg(mark1, mark2, mark3, mark4, mark5);
  cout << "The average of those marks is: " << average << endl;

  return 0;
}

double avg(int a, int b, int c, int d, int e){
  // Calculates average and return as precision
  return static_cast<double>(a + b + c + d + e) / 5;
}