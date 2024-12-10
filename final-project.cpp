/*
Name: Little Red Riding Hood's Adventure
Cảm hứng: "Little Red Riding Hood"
Guide Little Red Riding Hood to overcome all challenges.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Function containing the context
void printContext() {
    std::cout << "Context: Little Red Riding Hood is on her way to Grandma's house and must overcome various challenges." << std::endl;
    std::cout << "Objective: Choose the right items to overcome the challenges." << std::endl;
    std::cout << "Command: Choose 1, 2, or 3." << std::endl;
}

// Class containing the challenge
class Challenge {
public:
    std::string name;
    std::string description;
    std::string chosenItem;
    std::string alternativeItem1;
    std::string alternativeItem2;
    std::string rewardItem;

    Challenge(std::string n, std::string desc, std::string chosen, std::string alt1, std::string alt2, std::string reward)
        : name(n), description(desc), chosenItem(chosen), alternativeItem1(alt1), alternativeItem2(alt2), rewardItem(reward) {}
};

int main() {

    // Call the function to print the context
    printContext();

    // Get player name
    std::string userName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);
    std::cout << "Welcome, " << userName << "! Let's start your adventure." << std::endl;

    // Ask if the player is ready or not
    std::string ready;
    std::cout << "Are you ready to play? (y/n or yes/no): ";
    
    std::getline(std::cin, ready);

    // Handle errors with try - catch
    try {
        if (ready == "y" || ready == "Y" || ready == "yes" || ready == "YES") {
            std::cout << "Great! Let's start your adventure." << std::endl;
        } else if (ready == "n" || ready == "N" || ready == "no" || ready == "NO") {
            std::cout << "No problem, you can start again when you're ready." << std::endl;
            return 0;
        } else {
            throw std::invalid_argument("Invalid choice");
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << ". Please enter y/n or yes/no." << std::endl;
        return 0;
    }

    // Start the game

    // Create a vector containing challenges
    std::vector<Challenge> challenges = {
        {"The forest", "Face the wolf", "Sword", "Apple", "Water", "Cloak"},
        {"The village", "Solve the villagers' puzzle", "Book", "Candle", "Torch", "Bow and arrows"},
        {"The cave", "Find the way out", "Map", "Compass", "Flashlight", "Shield"},
        {"The ice river", "Cross the ice bridge", "Skates", "Snowboard", "Climbing shoes", "Armor"},
        {"The castle", "Defeat the wizard", "Amulet", "Chair", "Magic", "Sword"},
        {"The city", "Find the clues", "Magnifying glass", "Map", "Flashlight", "Key"},
        {"The desert", "Find a water source", "Water bottle", "Compass", "Hat", "Tent"},
        {"The island", "Build a shelter", "Saw", "Hammer", "Rope", "Tent"},
        {"The final boss", "Defeat the final boss", "Sword", "Amulet", "Magic", "Crown"}
    };

    std::vector<std::string> collectedRewards;
    std::srand(unsigned(std::time(0)));

    int lives = 3; // Initialize the number of lives

    // Generate a random number to select challenges random
    int randomChallenge = std::rand() % challenges.size();
    bool randomChoiceMade = false; // Flag to track random choice

    // Loop through the challenges
    for (size_t i = 0; i < challenges.size(); ) {
        const auto& challenge = challenges[i];
        std::cout << "Challenge: " << challenge.name << std::endl;
        std::cout << "Instruction: " << challenge.description << std::endl;

        std::vector<std::string> options = {challenge.chosenItem, challenge.alternativeItem1, challenge.alternativeItem2};
        std::random_shuffle(options.begin(), options.end());

        std::cout << "Your choice: " << std::endl;
        for (size_t j = 0; j < options.size(); ++j) {
            std::cout << j + 1 << ". " << options[j] << std::endl;
        }

        int choice;
        if (i == randomChallenge && !randomChoiceMade) {
            // Use random number to select a challenge randomly for a more unpredictable game experience
            choice = std::rand() % 3 + 1;
            std::cout << "The system has automatically selected the answer for you: " << choice << std::endl;
            randomChoiceMade = true;
        } else {
            std::cout << "Enter your choice (1, 2, or 3): ";
            std::cin >> choice;
        }

        std::string currentChoice = options[choice - 1]; // Save the current choice

        // Check the player's choice and process the corresponding outcome
        switch (choice) {
            case 1:
            case 2:
            case 3:
                if (currentChoice == challenge.chosenItem) {
                    if (i == challenges.size() - 1) { // Check if it's the last challenge
                        if (collectedRewards.size() > 5) {
                            std::cout << "Congratulations! You have defeated the final boss and won the game!" << std::endl;
                            return 0;
                        } else {
                            std::cout << "You need to collect more than 5 items to defeat the final boss." << std::endl;
                            --lives;
                            if (lives > 0) {
                                std::cout << "You have " << lives << " lives left." << std::endl;
                                if (i > 0) --i;
                            } else {
                                std::cout << "You have run out of lives. The game is over." << std::endl;
                                return 0;
                            }
                        }
                    } else {
                        std::cout << "Congratulations! You have chosen the correct item." << std::endl;
                        collectedRewards.push_back(challenge.rewardItem);
                        ++i;
                    }
                } else {
                    std::cout << "Sorry, you have chosen the wrong item." << std::endl;
                    --lives;
                    if (lives > 0) {
                        std::cout << "You have " << lives << " lives left." << std::endl;
                        if (i > 0) --i;
                    } else {
                        std::cout << "You have run out of lives. The game is over." << std::endl;
                        return 0;
                    }
                }
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
        }        
    }

    // Display the items collected by the player
    std::cout << "The items you have collected: " << std::endl;
    for (const auto& reward : collectedRewards) {
        std::cout << "- " << reward << std::endl;
    }

    return 0;
}
