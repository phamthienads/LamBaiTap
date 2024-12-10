#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function prototypes
void displayPrizes(const string prizes[], int prizeCount);
int calculateScore(int baseScore);

int main() {
    // Initialize random number generator
    srand(static_cast<unsigned>(time(0)));

    // Welcome the player
    string playerName;
    cout << "Welcome to the game! What is your name? ";
    getline(cin, playerName);
    cout << "Hello, " << playerName << "! Let's start the game!" << endl;

    // Generate a random number
    int randomNumber = rand() % 3 + 1;

    // Switch statement to determine the scenario
    string prize;
    switch (randomNumber) {
        case 1:
            prize = "Gold Cup";
            cout << "You found a Gold Cup!" << endl;
            break;
        case 2:
            prize = "Silver Medal";
            cout << "You found a Silver Medal!" << endl;
            break;
        case 3:
            prize = "Bronze Badge";
            cout << "You found a Bronze Badge!" << endl;
            break;
        default:
            cout << "No prize found!" << endl;
            break;
    }

    // Add a while loop to play the game again
    char playAgain;
    while (true) {
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') {
            cout << "Thank you for playing, " << playerName << "!" << endl;
            break;
        } else if (playAgain == 'y' || playAgain == 'Y') {
            cout << "Restarting the game..." << endl;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }

    // Use a for loop to display the collected prizes
    string prizes[] = {"Gold Cup", "Silver Medal", "Bronze Badge"};
    int prizeCount = 3;
    cout << "\nHere are all the possible prizes: " << endl;
    displayPrizes(prizes, prizeCount);

    // Function to calculate the final score
    int baseScore = 100;
    int finalScore = calculateScore(baseScore);
    cout << "Your final score is: " << finalScore << endl;

    return 0;
}

// Function to display the list of prizes
void displayPrizes(const string prizes[], int prizeCount) {
    for (int i = 0; i < prizeCount; i++) {
        cout << "- " << prizes[i] << endl;
    }
}

// Function to calculate the final score
int calculateScore(int baseScore) {
    int multiplier = rand() % 5 + 1; // Random multiplier from 1 to 5
    return baseScore * multiplier;
}
