#include <iostream>
using namespace std;

int main() {
    int userScore = 30;
    int& scoreRef = userScore;

    cout << "userScore = " << userScore << ", scoreRef = " << scoreRef << endl;

    scoreRef = 145;

    cout << "userScore = " << userScore << ", scoreRef = " << scoreRef << endl;

    return 0;
}