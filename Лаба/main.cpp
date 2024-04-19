#include <iostream>
#include <string>
#include "DogShelter.h"
void print_menu() {
    std::cout << "\n1. Add a new dog \n";
    std::cout << "2. Display all dogs\n";
    std::cout << "3. Save data to file\n";
    std::cout << "4. Load data from file\n";
    std::cout << "5. Remove a dog\n";
    std::cout << "6. Search by breed\n";
    std::cout << "7. Edit a dog\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    DogShelter shelter;
    int choice = 0;
    do {
        print_menu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Dog newDog;
            std::cin >> newDog;
            shelter.addDog(newDog);
            break;
        }
        case 2:
            shelter.displayDogs();
            break;
        case 3: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            shelter.saveToFile(filename);
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            shelter.loadFromFile(filename);
            break;
        }
        case 5: {
            int indexToRemove;
            std::cout << "Enter the index of the dog to remove: ";
            while (true) {
                if (std::cin >> indexToRemove) {
                    shelter.removeDog(indexToRemove - 1); // Adjust index to start from 1
                    break;
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter correct index ";
                }
            }
            break;
        }
        case 6: {
            std::string targetBreed;
            std::cout << "Enter the breed to search for: ";
            std::cin >> targetBreed;
            shelter.searchByBreed(targetBreed);
            break;
        }
        case 7: {
            int indexToEdit;
            Dog newDogData;
            std::cout << "Enter the index of the dog to edit: ";
            while (true) {
                if (std::cin >> indexToEdit) {
                    break;
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter correct index ";
                }
            }

            std::cin >> newDogData; // Read new data for the dog
            shelter.editDog(indexToEdit - 1, newDogData); // Adjust index to start from 1
            break;
        }
        case 8:
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 8);
    return 0;
}