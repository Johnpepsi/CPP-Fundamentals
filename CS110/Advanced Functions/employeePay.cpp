//Please complete this exercise using the description in the lab notes
// bi-weekly calculation

#include <iostream>
#include <iomanip>
using namespace std;

// Fucntion is implemented for details hrPay and perWork
void getDetails(double &hrPay, double &hrWork) {
  cout << "Please enter pay rate per hour: ";
  cin >> hrPay;
  cout << "Please enter hours worked: ";
  cin >> hrWork;
}

// Function is implemented for calculating total earnings
double calculatePay(double hrlyPay, double hrlyWork){
  return hrlyPay * hrlyWork;
}

// Function that prompts user pay information
void showPaymentDetails(double hrlyPay, double hrlyWork, double totalPayments) {
  cout << "You worked " << hrlyWork << "hours at $" << fixed << setprecision(2) << hrlyPay << "per hour. \n";
  cout << "Your total pay is $" << fixed << setprecision(2) << totalPayments << endl;
}

int main(){
  cout << "This program calculates total pay for an employee.";
  
  double hrPay, hrWork;
  getDetails(hrPay, hrWork);

  double totalPay = calculatePay(hrPay, hrWork);

  // Prompting user now for payments information
  showPaymentDetails(hrPay, hrWork, totalPay);

  return 0;
}

// hii
