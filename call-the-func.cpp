#include <iostream>
using namespace std;

void checkValue() {

    cout << "Checking value..." << endl;
    int value = 10;
    if (value > 0) {
        cout << "The value is positive." << endl;
    } else if (value < 0) {
        cout << "The value is negative." << endl;
    } else {
        cout << "The value is zero." << endl;
    }
}

int main() {
    checkValue();
    return 0;
}
