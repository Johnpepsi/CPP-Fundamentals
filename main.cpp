#include <iostream>
using namespace std;

struct Student

{
    string name;
    int id;
    int mark[2];
};

void printStudent(const Student& c);
Student readStudent();

int main(){
    Student stu;
    Student stu2= { "Mary Contrary", 1222222};
    Student stu3= { "John Palaganas", 2444444};
    
    stu=readStudent();
    printStudent(stu);
    cout << endl << " Another Student: " << endl;
    printStudent(stu2);
    
}

void printStudent(const Student& c)
{
    int i;
    
    cout << endl;
    cout << "Employee Name: " << c.name << endl;
    cout << "Employee ID: " << c.id << endl;
    for (i = 0; i < 3; i++)
    {
        cout << "The Employee info is: " << i+1 << ": " << c.mark[i] << " " << endl;
    }
}
Student readStudent(){
    int i;
    
    Student tempStu;
    cout << "Employee Name?: ";
    getline(cin, tempStu.name);
    cout << "Employee ID?: ";
    cin >> tempStu.id;
    for (i = 0; i < 3; i++)
    {
        cout << "Employee Yearly Salary" << i+1 << "?: ";
        cin >> tempStu.mark[i];
    }
    return tempStu;
    
}
