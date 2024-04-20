#include <iostream>

using namespace std;

int main(){

	int sum = 0;

	for (int i = 1; i <= 10; i++)
		sum += i;
		cout << "Sum from 1 to 10 is " << sum << endl;

	return 0;
}

// The loop iterates from 1 to 10 and adds each value of i to sum. 
// Here's how the sum accumulates:

// sum = 0
// After the first iteration (i = 1): sum = 0 + 1 = 1
// After the second iteration (i = 2): sum = 1 + 2 = 3
// After the third iteration (i = 3): sum = 3 + 3 = 6
// After the fourth iteration (i = 4): sum = 6 + 4 = 10
// After the fifth iteration (i = 5): sum = 10 + 5 = 15
// After the sixth iteration (i = 6): sum = 15 + 6 = 21
// After the seventh iteration (i = 7): sum = 21 + 7 = 28
// After the eighth iteration (i = 8): sum = 28 + 8 = 36
// After the ninth iteration (i = 9): sum = 36 + 9 = 45
// After the tenth iteration (i = 10): sum = 45 + 10 = 55
