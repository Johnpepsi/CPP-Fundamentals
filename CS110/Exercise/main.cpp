#include <iostream>
#include <string>

using namespace std;

int main()
{
  
    cout << "Hello my name is John Palaganas. \n" << endl;

    // Greet friend with a message
    string userName;
    cout << "What's your name? ";
    getline(cin, userName);
    cout << "Nice to meet you, " << userName << "! \n" << endl;

    // Fun Change: Asking my friend about their favorite color
    string favoriteColor;
  
    cout << "By the way, What's your favorite color? ";
    getline(cin, favoriteColor);
    cout << "Wow, " << favoriteColor << " is a fantastic color! \n" << endl;

    // Asks for my friend's age
    int age;
    cout << "How old are you, " << userName << "? ";
    cin >> age;
    
    if (age > 12) {
        cout << "You are old enough, please go ahead. \n" << endl;
    } else if (age < 18) {
        cout << "You are pretty young at your age. \n" << endl;
    } else {
        cout << "Good enough, come in. \n" << endl;
    }

    cout << "Thanks for sharing, " << userName << "! It appears you're " << age << " years old."<< endl;
    cout << "My pleasure to meet you and take care of yourself!" << endl;

    return 0;
}

