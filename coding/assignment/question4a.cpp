#include <iostream>
using namespace std;

int main() {
    for (char ch = 'A'; ch <= 'E'; ch++) {
        for (int j = 'A'; j <= ch; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}
