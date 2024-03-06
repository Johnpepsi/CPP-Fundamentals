// Program Convert converts a temperature in Fahrenheit to
// Celsius or a temperature in Celsius to Fahrenheit
// depending on whether the user enters an F or a C.

#include <iostream>
using namespace std;

int main() {
  char letter;  // Place to store input letter
  int tempIn;   // Temperature to be converted
  int tempOut;  // Converted temperature
  char choice; //  Store if the user wants to convert another temperature

  // Begin do-while loop here
 do {
   cout << "Input Menu" << endl << endl;
   cout << "F: Convert from Fahrenheit to Celsius" << endl;
   cout << "C: Convert from Celsius to Fahrenheit";
     cout << "\n" <<endl;

   // Loop until the user enters a matcehs letter
   do {
       cout << "Type a C or an F, then press return: ";
       cin >> letter;
       cout << "\n";

       // If the input is not a C, c, F, or f, prompt the user again
       if (letter != 'C' && letter != 'c' && letter != 'F' && letter != 'f') {
             cout << "Wrong letter, please enter C or F." << endl;
         }
     } while (letter != 'C' && letter != 'c' && letter != 'F' && letter != 'f');

    cout << "Type an integer number, then press return: ";
    cin >> tempIn;
    cout << "\n";

   if (letter == 'C' || letter == 'c') {
       tempOut = (9 * tempIn / 5) + 32;
   } else {
       tempOut = 5 * (tempIn - 32) / 9;
   }
   cout << "Temperature to convert: " << tempIn << endl;
   cout << "Converted temperature: " << tempOut << endl;
    cout << "\n";

   // Prompt user questionare
   cout << "Do you want to convert another temperature (y/n)? ";
   cin >> choice;

 // End do-while loop here - repeat loop
 } while (choice == 'y' || choice == 'Y');

   return 0;
}