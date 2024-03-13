/*************************************************
 * Student Name: John Palaganas
 * Student Number: 200480405
 * Replit User Name: <~~jpl653~~<<
 * Acitvity: Lab 8 Exercise 1 - 3
 * Program Name: ex3_is_even.cpp
 * Last Modified: March 05 2024
 * Learning: Program to test "is_even" function.
 *************************************************/

#include <iostream>
using namespace std;


void is_even(int); // Function Prototype


int main()
{
  int num;

  cout << "Enter an integer: ";
  cin >> num;
  cout << "Is " << num << " even?  ";

  is_even(num);

  cout << endl;

  return 0;
}


// *is_even* Function Definition.
// Prints "yes" if a is even, "no" otherwise.
void is_even(int a) {
  // ADD: code here to complete the function
  // use if else structure
  if (a % 2 == 0) {
    cout << "Yes it is!"; 
  } else {
    cout << "Not it's not!";
  }
}