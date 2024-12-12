#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Parent class
class Character {
protected:
    std::string name;
    std::string characteristic;

public:
    Character(const std::string& name, const std::string& characteristic)
        : name(name), characteristic(characteristic) {}

    virtual void interact() const = 0; // Pure virtual method

    virtual ~Character() {}
};

// Child class: Family member
class Family : public Character {
public:
    Family(const std::string& name, const std::string& characteristic)
        : Character(name, characteristic) {}

    void interact() const override {
        std::cout << "You have met " << name << ". " << name << " is " << characteristic << ". They give you a gift!\n";
    }
};

// Child class: Pet
class Pet : public Character {
private:
    std::string type;

public:
    Pet(const std::string& name, const std::string& type, const std::string& characteristic)
        : Character(name, characteristic), type(type) {}

    void interact() const override {
        std::cout << "You have met " << name << ", a " << type << ". " << name << " is " << characteristic;
        if (characteristic == "mean") {
            std::cout << ". You should run!\n";
        } else {
            std::cout << ". They play with you!\n";
        }
    }
};

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Create instances of Family and Pet
    Family father("Ron", "helpful");
    Pet pet1("Zippy", "kangaroo", "mean");
    Pet pet2("Buddy", "dog", "friendly");

    // Store characters in an array of pointers
    Character* characters[] = { &father, &pet1, &pet2 };
    int numCharacters = sizeof(characters) / sizeof(characters[0]);

    // Randomly encounter a character
    std::cout << "You are in a park with lots of families and animals around:\n";
    int randomIndex = std::rand() % numCharacters;
    characters[randomIndex]->interact();

    return 0;
}