#include "Dog.h"
#include <iostream>
#include <sstream>
#include <string>

void Dog::editBreed(const std::string& newBreed) {
    breed = newBreed;
}
std::ostream& operator<<(std::ostream& os, const Dog& dog) {
    os << "Breed: " << dog.breed << ", Birth Year: " << dog.birthYear << ", Vaccinated: " << (dog.vaccinated ? "Yes" : "No");
    return os;
}

std::istream& operator>>(std::istream& is, Dog& dog) {
    std::cout << "Enter Breed: ";
    is >> dog.breed;
    std::string input1;
    std::string input2;
    std::cout << "Enter Birth Year: ";
    while (true) {
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input1);
        std::istringstream iss(input1);
        if (iss >> dog.birthYear) {
            break;
        }
        else {
            std::cout << "Enter Correct Birth Year: ";
        }
    }
    std::cout << "Is Vaccinated? (1 for Yes, 0 for No): ";
    while (true) {
        std::getline(std::cin, input2);
        std::istringstream iss(input2);
        if (iss >> dog.vaccinated) {
            break;
        }
        else {
            std::cout << "Enter Correct (1 for Yes, 0 for No)";
        }
    }
    return is;
}