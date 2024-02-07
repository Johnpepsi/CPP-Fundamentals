#include <iostream>
#include <string>

using namespace std;
int main()
{

  string oldSentence;
  oldSentence = "The quick brown dog jumped WAY over the lazy cat.";

  // ADD CODE HERE: display the content of oldSentence
  cout << "Original sentence: " << oldSentence << endl;

  // ADD CODE HERE: display the length of oldSentence
  cout << "Length of the original sentence: " << oldSentence.length() << endl;


  //////////////////////////////////////////////////
  // Do not make any change to the following code.
  // Just read and understand this program.
  //////////////////////////////////////////////////

  // To create a new sentence without "WAY ":


  // 1) Create a string with "WAY " in it - our *s*earch string
  string s = "WAY ";


  // 2) find the position of "WAY " using the search string with oldSentence
  int pos = oldSentence.find(s);
  cout << "pos is " << pos << endl;


  // 3) get the characters up to "WAY "
  string newSentence = oldSentence.substr(0, pos);
  cout << "Modified sentence: " << newSentence << endl;


  // 4) append the characters after "WAY "
  // Adding the length of s to pos gives a position
  // just after where s appears in oldSentence...
  // Leave the second argument of substr() out to get the rest of the line.
  newSentence += oldSentence.substr(pos + s.length());


  // 3) & 4) ALTERNATE: you can do both substrings in one step
  // newSentence = oldSentence.substr(0, pos) + oldSentence.substr(pos + s.length());


  cout << "Completed sentence: " << newSentence << endl;

  return 0;
}