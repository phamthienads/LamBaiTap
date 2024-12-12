#include <iostream>
using namespace std;

int main() {
    int choice;
    
    cout << "Welcome! Choose an option:\n";
    cout << "1. Check even or odd\n";
    cout << "2. Find the largest of two numbers\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int number;
        cout << "Enter a number: ";
        cin >> number;
        if (number % 2 == 0) {
            cout << "The number is even.\n";
        } else {
            cout << "The number is odd.\n";
        }
    } else if (choice == 2) {
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        if (a > b) {
            cout << "The largest number is " << a << ".\n";
        } else if (b > a) {
            cout << "The largest number is " << b << ".\n";
        } else {
            cout << "Both numbers are equal.\n";
        }
    } else if (choice == 3) {
        cout << "Exiting the program. Goodbye!\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
