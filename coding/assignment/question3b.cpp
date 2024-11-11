#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int duckCount = 0;

    do {
        cout << "Enter 'duck' or 'goose': "; // display to choose
        cin >> input; // inputs user to choose either goose or duck

        if (input == "duck") {
            duckCount++;
        }

    } while (input != "goose");

    cout << "Number of 'duck' entries: " << duckCount << endl;
    return 0;
}
