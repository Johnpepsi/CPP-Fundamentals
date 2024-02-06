#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the distance between two points
double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a triangle given the lengths of its sides
double calculate_triangle_area(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Function to calculate future investment value
double calculate_future_investment(double investmentAmount, double annualInterestRate, double years) {
    double monthlyInterestRate = annualInterestRate / 12 / 100;
    return investmentAmount * pow((1 + monthlyInterestRate), years * 12);
}

int main() {
    // Variables for triangle area calculation
    double x1, y1, x2, y2, x3, y3, side1, side2, side3, triangle_area;

    // Prompt user for points of the triangle
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Enter the coordinates of the third point (x3, y3): ";
    cin >> x3 >> y3;

    // Calculate side lengths
    side1 = calculate_distance(x1, y1, x2, y2);
    side2 = calculate_distance(x2, y2, x3, y3);
    side3 = calculate_distance(x3, y3, x1, y1);

    // Calculate the area of the triangle
    triangle_area = calculate_triangle_area(side1, side2, side3);
    cout << "The area of the triangle is: " << triangle_area << endl;

    // Variables for future investment value calculation
    double investmentAmount, annualInterestRate, years, futureInvestmentValue;

    // Prompt user for investment details
    cout << "Enter the investment amount: ";
    cin >> investmentAmount;
    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> annualInterestRate;
    cout << "Enter the number of years: ";
    cin >> years;

    // Calculate the future investment value
    futureInvestmentValue = calculate_future_investment(investmentAmount, annualInterestRate, years);
    cout << "The future investment value is: " << futureInvestmentValue << endl;

    return 0;
}
