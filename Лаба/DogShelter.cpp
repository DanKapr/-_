#include "DogShelter.h"

DogShelter::DogShelter() : dogs(nullptr), size(0), capacity(0) {}DogShelter::~DogShelter() {
    delete[] dogs;
}

void DogShelter::addDog(const Dog& newDog) {
    if (size == capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        Dog* temp = new Dog[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = dogs[i];
        }
        delete[] dogs;
        dogs = temp;
    }
    dogs[size++] = newDog;
}

void DogShelter::displayDogs() {
    for (int i = 0; i < size; ++i) {
        std::cout << "Dog " << i + 1 << ": " << dogs[i] << std::endl;
    }
}

void DogShelter::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file << dogs[i].breed << " " << dogs[i].birthYear << " " << dogs[i].vaccinated << std::endl;
        }
        file.close();
        std::cout << "Data saved to file." << std::endl;
    }
    else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void DogShelter::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    while (size != 0) {
        removeDog(size - 1);
    }
    if (file.is_open()) {
        do {
            std::string breed;
            int birthYear;
            bool vaccinated;
            file >> breed >> birthYear >> vaccinated;
            addDog(Dog(breed, birthYear, vaccinated));
        } while (!file.eof());
        file.close();
        std::cout << "Data loaded from file." << std::endl;
    }
    else {
        std::cerr << "Unable to open file." << std::endl;
    }
    removeDog(size - 1);
}

void DogShelter::removeDog(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; ++i) {
            dogs[i] = dogs[i + 1];
        }
        size--;
    }
    else {
        std::cerr << "Invalid index. Cannot remove dog." << std::endl;
    }
}


void DogShelter::searchByBreed(const std::string& targetBreed) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (dogs[i].breed == targetBreed) {
            found = true;
            std::cout << "Dog found at index " << i + 1 << ": " << dogs[i] << std::endl;
        }
    }
    if (!found) {
        std::cout << "Dog with breed '" << targetBreed << "' not found." << std::endl;
    }
}

void DogShelter::editDog(int index, const Dog& newDogData) {
    if (index >= 0 && index < size) {
        dogs[index] = newDogData;
    }
    else {
        std::cerr << "Invalid index. Cannot edit dog." << std::endl;
    }
};