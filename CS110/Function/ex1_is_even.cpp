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
