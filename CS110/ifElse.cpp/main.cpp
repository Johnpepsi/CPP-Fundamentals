#include <iostream>
#include <string>

using namespace std;

int main() {

  // follow up question: on number 4. Do we need to create a data types for my
  // friend? Or we can just
  // mention their name by implemeting cout ...

  // Extended Welcome Phase
  cout << "This program will greet you and ask for some information." << endl;

  // Greet friend with a message
  string userName;
  cout << "Hello there! What's your name? ";
  getline(cin, userName);
  cout << "Hi " << userName << "! Nice to meet you." << endl;

  // Fun Change: Asking my friend about their favorite color
  string favoriteColor;

  cout << "By the way, what's your favorite color? ";
  getline(cin, favoriteColor);
  cout << "Wow, " << favoriteColor << " is a fantastic color!" << endl;

  // Ask for my friend's age
  int age;
  cout << "How old are you, " << userName << "? ";
  cin >> age;

  // If else starts here
  if (age > 18) {
    cout << "Good, big pototoy na ah." << endl;
     } else if (age < 15) {
    cout << "You're to young bata uwi kana." << endl;
     } else {
    cout << "You are good to go!" << endl;
     }

    cout << "Thanks for sharing, " << userName << "!" << " It appears you're " << age << " years old." << endl;
    cout << "My pleasure to meet you and have a great day!" << endl;

    return 0;
}
