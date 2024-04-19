#include <fstream>
#include "Dog.h"

class DogShelter {
private:
    Dog* dogs;
    int size;
    int capacity;

public:
    DogShelter();
    ~DogShelter();

    void addDog(const Dog& newDog);
    void displayDogs();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void removeDog(int index);
    void searchByBreed(const std::string& targetBreed);
    void editDog(int index, const Dog& newDogData);
};
