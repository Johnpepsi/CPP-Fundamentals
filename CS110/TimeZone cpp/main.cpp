 /*************************************************
   * Student Name: John Palaganas
   * Student Number: 200480405
   * Replit User Name: <~~jpl653~~<<
   * Assignment Number: CS 110 Assignment 1 Question 3 & 4
   * Program Name: A1Q4.cpp
   * Last Modified: January 19 2024
   *************************************************/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {

  // Here is my prompt name
  string myName = "John Palaganas";

  // This prompt is to request for the users name
  cout << "Enter your name here: ";
  string myFriend;
  cin >> myFriend;

  // Utilizing date program, run by the machine
  auto currentTime = system_clock::now();
  auto sixHours = hours(6);

  // localTime starts in here
  // had to use sixHours as for Regina, SK Timezone
  auto localTime = system_clock::to_time_t(currentTime - sixHours);


  // Letter message for friend as an artiicle format
  cout << "\n Hey " << myFriend << ",\n\n";

  cout << "This message I'm writing is at -> " << put_time(localtime(&localTime), "%Y-%m-%d %H:%M:%S \n") << endl;

  cout << "I hope you are better, My friend I am learning the C++ that will make people lives even more easier."
       << "Crazy how I learned the program from CS110. Here is the plan. What I'm going to do is." << endl;
  cout << "Learn all the basic fundametals of C++ so I can build more Systems as a project."
       << "Such as Student attendance, Inventory Management System or any random stuff." << endl;
  cout << "This message is also written in High-level Language!"
       << "It's pretty awesome, you think?\n\n" << endl;

  cout << "Cheers! " << endl;
  cout << "Your Friend, " << myName << endl;

  return 0;
}
