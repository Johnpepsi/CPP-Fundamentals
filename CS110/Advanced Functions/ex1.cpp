#include <iostream>
using namespace std;


// Function prototypes:
void getValues(double &, double &);
float computeArea(double, double);
void printArea(double);


int main()
{
  // Function l w and area
  double length, width, area;

  cout << "This program computes the area of a rectangle." << endl;
  cout << "You will be prompted to enter both the length and width." << endl;
  cout << "Enter a real number (such as 7.88 or 6.3) for each." << endl;
  cout << "The program will then compute and print the area.";
  cout << endl;

  // call function getValues(length, width) here
  getValues(length, width);
  area = computeArea(length, width);
  // call function computeArea(length, width) here
  // call function printArea(area) here
  printArea(area);
  
  return 0;
}
/*
  Purpose:  To ask the user for the length and width of a rectangle and
            to return these values via the two parameters.
  Return:   Length   The length entered by the user.
            Width    The width entered by the user.
*/
void getValues(double &l, double &w)
{
  // add code to get Length and Width
 cout << "Enter the length of the rectangle here: ";
 cin >> l;
 cout << "Enter the width of the rectangle here: ";
 cin >> w;
}

/* Given:  Length   The length of the rectangle.
           Width    The width of the rectangle.
   Purpose:   To compute the area of this rectangle.
   Return: The area in the function name.
*/

float computeArea(double l, double W)
{
  // add code to compute area
 return l * W;
}

/* Given:  Area    The area of a rectangle.
   Purpose:   To print Area.
   Return: Nothing.
*/
void printArea(double a)
{
	// add code to print area of the rectangle
  cout << "The area of the rectangle is going to be: " << a << endl; 
}