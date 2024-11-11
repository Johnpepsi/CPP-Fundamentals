#include <iostream>
using namespace std;

// Define function `a` with a default parameter
void a(int x = 123) {
    cout << x << endl;
}

// Define function `b` with a default parameter
void b(string x = "ABC") {
    cout << x << endl;
}

int main() {
    // Call the functions with and without arguments
    a();
    a(456);
    b();
    b("xyz");

    return 0;
}
