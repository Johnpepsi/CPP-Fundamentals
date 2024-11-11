#include <iostream>
using namespace std;

int main() {
    int classesHeld, classesAttended;
    float attendancePercentage;

    //number of classes held and attended
    cout << "Enter the number of classes held: ";
    cin >> classesHeld;
    cout << "Enter the number of classes attended: ";
    cin >> classesAttended;

    //calculates attendance percentage
    attendancePercentage = (static_cast<float>(classesAttended) / classesHeld) * 100;

    // outputs attendance percentage
    cout << "Attendance Percentage: " << attendancePercentage << "%" << endl;

    // it checks if student is allowed to sit in the exam
    if (attendancePercentage >= 75) {
        cout << "Student is allowed to sit in the exam." << endl;
    } else {
        cout << "Student is NOT allowed to sit in the exam." << endl;
    }

    return 0;
}
