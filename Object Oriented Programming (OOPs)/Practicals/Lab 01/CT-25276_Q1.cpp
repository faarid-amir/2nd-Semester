#include <iostream> 
using namespace std;

int main() {
    int rollno;
    string subjects[5] = {"OOPs", "Calculus", "PS", "DS", "LDST"};
    int Marks[5];
   int total = 0;
 
    cout << "Enter your roll number: ";
    cin >> rollno;

    cout << "Enter your marks out of 100:" << endl;
    for (int i = 0; i< 5; i++) {
        cout << "Enter your marks in " << subjects[i] << ": ";
        cin >> Marks[i];
        total += Marks[i];
    }

    float percentage = (float(total) / 500) * 100;

    cout << "Roll Number: " << rollno << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Percentage: " << percentage << "%" << endl;


}