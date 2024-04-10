// By studying this program, you can gain insights into randomization techniques, string manipulation, user input handling, function implementation, 
// logical operations, and output formatting, which may be relevant for your finals, 
// especially if they cover topics related to programming, algorithms, or cybersecurity.

//Generate a certain length password by given no of capital, small, digit, special  
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const string capLetters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //26
const string smallLetters="abcdefghijklmnopqrstuvwxyz";//26
const string digits="0123456789"; //10
//const string specialChar="!#$%&()*+,-.:;<=>?@[]^_{|}~"; //27 
const string specialChar="!@#$%^&*()"; //10 

//pick len letters from sLen long source 
string pickLetters(int len, string source, int sLen)
{
 int i;
 string picked="";

 for (i=0; i<len; i++)
   picked = picked +source.at(rand()%sLen);

 return picked;
}

//shuffle picked letters
string shuffleWord(string old)
{
  string newWord;
  int i, j, len;
  char ch;

  len = old.length();
  newWord = old;

  //random swap
  for (i=0; i< len; i++) //0-len-2
    {
     ch = newWord [i];
     j= rand()%(len-1); //if len len-1 did twice  
     newWord [i] = newWord [j];
     newWord [j] = ch;
    }

   return newWord ;
}

int main()
{
  string password;
  int length, capital, small, digit, special;
  int i, j;

  srand(time(NULL));    //initailize random generator
  password = "";
  j=0;

  cout << "length of password: ";
  cin >> length;

  cout << "number of capital letter: ";
  cin >> capital;

  cout << "number of small letters: ";
  cin >> small;

    cout << "number of digits: ";
    cin >> digit;

    cout << "number of special chracters: ";
    cin >> special;

    if (length < capital + small + digit + special)
       {cout << "length too short" << endl;
        return 1;
       }

  for (i=0; i<capital; i++)
    {
      password = password + char ('A'+ rand()%26);
    }

  password = password + pickLetters (digit, digits, 10);

  //password = password + pickLetters (special, specialChar, 27);
  password = password + pickLetters (special, specialChar, 10);

  password = password + pickLetters (length-capital-digit-special, smallLetters, 26);

  cout << endl;
  cout << "Initial passsword: " << password << endl
    << "length:" << password.length()<< endl;

  password = shuffleWord(password);

  cout<< "Shuffled passsword: " << password << endl

        << "length:" << password.length()<< endl;

      return 0;
    }
