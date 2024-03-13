// Program functionP prints a triangle of the stars.
// For example:
//		 *****
//		 ****
//		 ***
//		 **
//		 *

#include <iostream>
#include <iomanip>
using namespace std;

/* ADD: the function prototype for printStars */
void printStars(int num);

int main()
{
  int  numOfStars;

  cout << "Enter the number of stars in the first line: ";
  cin >> numOfStars;
  cout << "\n";
  
  while (numOfStars > 0)
  {
    /* ADD: code to invoke function *printStars* */
    printStars (numOfStars);
    /* ADD: code to update the control variable *numOfStars*  */
    numOfStars--;

    cout << endl;
  }

  return 0;
}

//****************************************************************************

void printStars(int num)
{
  /* ADD: code to print the *num* of stars in a line by using a loop*/
  for (int i = 0; i < num; ++i) {
    cout << "*";
  }
}