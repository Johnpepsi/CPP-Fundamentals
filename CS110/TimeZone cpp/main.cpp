 /*************************************************
   * Student Name: John Palaganas
   * Student Number: 200480405
   * Replit User Name: <~~jpl653~~<<
   * Assignment Number: CS 110 Assignment 1 Question 3 & 4
   * Program Name: A1Q4.cpp
   * Last Modified: January 24 2024
   *************************************************/

#include <iostream>
#include <ctime>   // This header provides functionality related in Date and Time.
#include <iomanip> // This header manipulates the formatting input and output streams.
#include <chrono>  // It includes the necessary functionality for working with
                  //  durations, timepoint, and clocks.

using namespace std;
using namespace chrono; // This line brings all the names from chrono namespace into current the scope

  int main() {

  // Here is my prompt name used of own variable so easy to call out
  string myName = "John Palaganas";

  // This prompt is to request for the users name
  cout << "Enter your name here: ";
  string myFriend;
  cin >> myFriend;

  // Utilizing date program, generated by the program
  auto currentTime = system_clock::now();
  auto currentUTC = system_clock::to_time_t(currentTime);

  // localTime starts in here
  // Had to use sixHours as for Regina, SK Timezone
  auto sixHours = hours(6);
  auto gmtTime = system_clock::to_time_t(currentTime - sixHours);

  // Letter message for friend as a proper format
  cout << "\n Hey " << myFriend << ",\n\n";

  // Calling out the variables to be able to show up the current time in users end
  cout << "\n Date of writing this letter: " << put_time(gmtime(&gmtTime), "%Y-%m-%d %H:%M:%S") << " Regina, SK \n\n" << endl;

  // Friendly Message starts in here with a proper format where its generate by the program.
  cout << "\n I hope you are better, My friend I am learning the C++ that will make people lives even more easier. "
       << "Crazy how I learned the program from CS110. Here is the plan. Here is what I'm going to do. "
       << "Learn all the basic fundametals of C++ so I can build more Systems as a project. "
       << "Such as Student attendance, Inventory Management System or any random stuff."
       << "This message is also written in High-level Language! "
       << "It's pretty awesome! \n\n" << endl;

  // End of letter message
  cout << "Cheers! " << endl;
  cout << myName << endl;

  return 0;
}
