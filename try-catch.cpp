#include <iostream>
#include <vector>
#include <stdexcept>

// Custom exception class
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom Exception: Input value is invalid.";
    }
};

int main() {
    try {
        
        // Enter a positive integer
        int userInput;
        std::cout << "Enter a positive integer: ";
        std::cin >> userInput;

        // Enter a value that is not an integer
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input. Expected an integer.");
        }

        // Enter a value less than 0
        if (userInput <= 0) {
            throw CustomException();
        }

        std::cout << "You entered: " << userInput << std::endl;

        // Enter values ​​outside the set
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::cout << "Enter an index to access (0-4): ";
        int index;
        std::cin >> index;

        // Enter values ​​outside the set
        if (index < 0 || index >= numbers.size()) {
            throw std::out_of_range("Index is out of bounds.");
        }

        std::cout << "Value at index " << index << ": " << numbers[index] << std::endl;

    // Enter a value that is not an integer
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    
    // Enter values ​​outside the set
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;

    // Enter a value less than 0
    } catch (const CustomException& e) {
        std::cerr << "Error: " << e.what() << std::endl;

    // Enter an unknown error
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    std::cout << "Program completed." << std::endl;
    return 0;
}
