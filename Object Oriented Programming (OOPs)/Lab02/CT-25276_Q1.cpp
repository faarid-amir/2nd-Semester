#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        int roll_no , sem;
        char sec;
    
};

int main() {
    Student std[4];
    cout << "Enter the details of students: \n";
    for (int i = 0; i<4 ; i++) {
        cout << "Student " << i+1 << ":\n";
        cout << "Name: ";
        cin >> std[i].name;
        cout << "Roll No: ";
        cin >> std[i].roll_no;
        cout << "Semester: ";
        cin >> std[i].sem;
        cout << "Section: ";
        cin >> std[i].sec;

    }

    cout << "\n=====Students of Section A=====\n";
    for(int i = 0; i<4; i++) {
        if(std[i].sec == 'A' || std[i].sec == 'a') {
            cout << "Name: " << std[i].name << " Roll No.: " << std[i].roll_no << " Semester: " << std[i].sem << " Section: " << std[i].sec << "\n";
        }
    }
    return 0;
}