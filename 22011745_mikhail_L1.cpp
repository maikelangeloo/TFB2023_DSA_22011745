#include <iostream>
#include <string>
using namespace std;


struct Person {
    string name;
    int id;
    int contact;
    string email;
};

int main() {
    Person student[10]; // Array of 10 Person structures

    // Prompting user to enter data for 10 students
    for (int i = 0; i < 10; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        
        cout << "Name: ";
        getline(cin, student[i].name);

        cout << "ID: ";
        cin >> student[i].id;

        cout << "Contact (number only): ";
        cin >> student[i].contact;

        cout << "Email: ";
        cin.ignore(); // Clear newline before using getline again
        getline(cin, student[i].email);
    }

    // Displaying data for 10 students
    cout << "\n--- Student Information ---\n";
    for (int i = 0; i < 10; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Contact: " << student[i].contact << endl;
        cout << "Email: " << student[i].email << endl;
    }

    return 0;
}
