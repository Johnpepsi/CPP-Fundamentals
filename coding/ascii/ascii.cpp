#include <iostream>
using namespace std;

int main(){
  char c, b;
  cout << "Enter Character for c: ";
  cin >> c;
  
  cout << "Enter Character for b: ";
  cin >> b;

  int a = c+b;
  
  cout << int(a) << endl; // to Print in ACII
  
  return 0;
}