#include <iostream>

using namespace std;

class User{
    
public: // There should be public to access this all out
    // This is all class
    string userName;
    string type;
    int hp;
    int mp;
    int level;
    int exp;
    
    // Constructor
    User(string aUsernName, string aType, int aHp, int aMp, int aLevel, int aExp) {
        userName = aUsernName;
        type = aType;
        hp = aHp;
        mp = aMp;
        level = aLevel;
        exp = aExp;
        
        cout << userName << " has now been Registered" << endl;
        cout << userName << " characteristic is " << type << endl;
        cout << userName << " life health " << hp << endl;
        cout << userName << " battery life " << mp << endl;
        cout << userName << " max level can go " << level << endl;
        cout << userName << " exprience as hero " << exp << endl;

    }
    
};

int main() {
    
    // This is still an object at pina-ikli lang to make it more clean by using Constructor method
    // Mas malinis tignan and its more clean than before
    User playerOne("John Pepsi", "Marksman" , 100, 200, 50, 100);
    cout << "\n";
    User playerTwo("Manny Pacquiao", "Boxer", 121, 132, 32, 456);
    cout << "\n";
    User playeThree("Jai Juan", "Lover", 144, 454, 34, 235);
    cout << "\n";
    
    return 0;
}
