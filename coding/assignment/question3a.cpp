#include <iostream>
using namespace std;

int main() {
    char c;

    do {
        cout << "Enter a character (Y/y/N/n): ";
        cin >> c;
    } while (c != 'Y' && c != 'y' && c != 'N' && c != 'n'); // lower case and upper cases

    cout << "You entered: " << c << endl;
    return 0;
}
