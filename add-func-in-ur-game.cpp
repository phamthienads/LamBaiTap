#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to calculate attack damage
int calculateDamage(int baseDamage, int level, int randomFactor) {
    return baseDamage + (level * 2) + randomFactor;
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Greet the player
    string playerName;
    cout << "Welcome, brave adventurer! What is your name? ";
    cin >> playerName;
    cout << "Greetings, " << playerName << "! Your journey begins now.\n";

    // Player setup
    int playerLevel = 1;
    int baseDamage = 10;
    int monsterHealth = 50;

    // Combat simulation
    cout << "You encounter a wild monster with " << monsterHealth << " health!\n";

    // Khai báo randomFactor ở đây
    int randomFactor = 0;

    while (monsterHealth > 0) {
        cout << "\nChoose your action:\n";
        cout << "1. Normal Attack\n";
        cout << "2. Special Attack\n";
        cout << "3. Defense\n";
        int choice;
        cin >> choice;

        // Generate random number first
        int randomValue = rand();

        // Use random number with switch-case
        switch(choice) {
            case 1:
                randomFactor = randomValue % 6;
                break;
            case 2:
                randomFactor = randomValue % 10 + 5;
                break;
            case 3:
                randomFactor = randomValue % 3;
                break;
            default:
                cout << "Invalid choice!\n";
                continue;
        }

        // Add animation loop for attack
        for(int i = 0; i < 3; i++) {
            cout << "Attacking" << string(i + 1, '.') << "\n";
        }

        // Calculate damage using the function
        int damage = calculateDamage(baseDamage, playerLevel, randomFactor);
        monsterHealth -= damage;

        // Add condition to check monster's health
        if (monsterHealth > 0 && monsterHealth < 20) {
            cout << "WARNING: The monster is going berserk! Its power increases!\n";
            damage = damage * 1.5;  // Increase damage
        }

        // Display attack details
        cout << playerName << " attacks the monster, dealing " << damage 
             << " damage! The monster's remaining health: " << monsterHealth << "\n";

        // Level up after defeating the monster
        if (monsterHealth <= 0) {
            cout << "You defeated the monster! Your level increases!\n";
            playerLevel++;
            break;
        }
    }


    cout << "Your adventure continues...\n";
    return 0;
}
