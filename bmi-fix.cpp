#include <iostream> // For input and output
#include <string>  // For using string data type
#include <cmath>   // For using mathematical functions

int main() {

    std::string name; // Variable to store username

    double weight, height, bmi;  // Variables to store weight, height, and BMI

    std::cout << "Enter Your Name: ";
    std::cin >> name;  // Get the user's name as input


    std::cout << "Enter Your Weight: ";
    std::cin >> weight;   // Get the user's weight as input


    std::cout << "Enter Your Height: ";
    std::cin >> height;  // Get the user's height as input

    bmi = 703 * weight / pow(height, 2);  // Use pow() to calculate height squared

    // Use if statements
    if (bmi < 18.5) {
        std::cout << name << ", You are underweight." << std::endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        std::cout << name << ", You have a normal weight." << std::endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        std::cout << name << ", You are overweight." << std::endl;
    } else {
        std::cout << name << ", You are obese." << std::endl;
    }

    std::cout << name << ", Your BMI is: " << bmi << std::endl;

    return 0;

}