// Program Convert converts a temperature in Fahrenheit to
// Celsius or a temperature in Celsius to Fahrenheit
// depending on whether the user enters an F or a C.

#include <iostream>
using namespace std;

int main()
{
  char letter;   // Place to store input letter
  int tempIn;    // Temperature to be converted
  int tempOut;   // Converted temperature
  char repeat;   // To store user's choice to repeat

  do {
    cout << "Input Menu" << endl << endl;
    cout << "F:  Convert from Fahrenheit to Celsius" << endl;
    cout << "C:  Convert from Celsius to Fahrenheit" << endl;

    // Ask for valid input until a correct letter is entered
    do {
      cout << "Type a C or an F, then press return." << endl;
      cin >> letter;

      if (letter != 'C' && letter != 'c' && letter != 'F' && letter != 'f') {
        cout << "Wrong letter. Please enter C or F." << endl;
      }
    } while (letter != 'C' && letter != 'c' && letter != 'F' && letter != 'f');

    cout << "Type an integer number, then press return." << endl;
    cin >> tempIn;

    // Conversion logic
    if (letter == 'C' || letter == 'c') {
      tempOut = (9 * tempIn / 5) + 32;
    } else {
      tempOut = 5 * (tempIn - 32) / 9;
    }

    cout << "Temperature to convert: " << tempIn << endl;
    cout << "Converted temperature: " << tempOut << endl;

    // Ask user if they want to convert another temperature
    cout << "Do you want to convert another temperature (y/n)? ";
    cin >> repeat;

  } while (repeat == 'y' || repeat == 'Y');  // Repeat loop if user typed 'y' or 'Y'

  return 0;
}
