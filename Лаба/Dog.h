#pragma once
#include <string>
#include <iostream>
class DogShelter;
class Dog {
    friend class DogShelter;
private:
    std::string breed;
    int birthYear;
    bool vaccinated;

public:
    Dog() : breed(""), birthYear(0), vaccinated(false) {}

    Dog(std::string breed, int birthYear, bool vaccinated) : breed(breed), birthYear(birthYear), vaccinated(vaccinated) {}

    friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
    friend std::istream& operator>>(std::istream& is, Dog& dog);
    void editBreed(const std::string& newBreed);
};
