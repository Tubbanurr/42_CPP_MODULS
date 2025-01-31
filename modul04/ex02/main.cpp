#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {


    const AAnimal* animals[4];

    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();


    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();


    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();


    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }


    //const Animal* meta = new Animal();

    //const Animal* j = new Dog();


    return 0;
}
