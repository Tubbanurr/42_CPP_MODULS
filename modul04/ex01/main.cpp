#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int size = 4;
    Animal* animals[size];


    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }


    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }


    for (int i = 0; i < size; i++) {
        delete animals[i];
    }


    std::cout << "\n--- Deep Copy Test ---\n";
    Dog dog1;
    Dog dog2 = dog1;
    dog1.getBrain()->ideas[0] = "Chase the ball!";
    dog2.getBrain()->ideas[0] = "Bark at the mailman!";
    dog1.getBrain()->ideas[1] = "Eat a bone!";
    dog2.getBrain()->ideas[1] = "Chase the cat!";
    std::cout << "Dog1's first idea: " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "Dog2's first idea (should be different): " << dog2.getBrain()->ideas[0] << std::endl;
    std::cout << "Dog1's second idea: " << dog1.getBrain()->ideas[1] << std::endl;
    std::cout << "Dog2's second idea: " << dog2.getBrain()->ideas[1] << std::endl;

    return 0;
}
