//Encrypting and Decrypting a String

#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int shift)
{
    for (char& c : text)
      {
        if (isalpha(c)) 
        {
            c = 'A' + (c - 'A' + shift) % 26;
        }
    }
    return text;
}

string decrypt(string text, int shift) 
{
    return encrypt(text, 26 - shift); // Decryption is the inverse operation of encryption
}

int main()
{
    string text;
    cout << "Enter a string to encrypt: ";
    getline(cin, text);

    int shift;
    cout << "Enter a shift value for encryption: ";
    cin >> shift;

    string encrypted = encrypt(text, shift);
    cout << "Encrypted string: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted string: " << decrypted << endl;

    return 0;
}
... (1 line left)
