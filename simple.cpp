#include <iostream>
#include <string>

int main() {

    std::string firstName;

    // 1) Say hello and ask for your name
    std::cout << "Hello! What's your name? ";
    std::cin >> firstName;

    // 2) Comment on their names
    std::cout << "Your name is beautiful, " << firstName << "!" << std::endl;

    // 3) Tell a computer joke
    std::cout << "Why can't computers fight? Because they are afraid of getting a 'virus'!" << std::endl;

    // 4) Say goodbye
    std::cout << "Goodbye, " << firstName << "! See you again!" << std::endl;

    return 0;
}
