#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n-- Animal Test --(DYNAMIC POLYMORPHIZM)\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n-- OBJECT PTR TYPE Test --(DYNAMIC POLYMORPHIZM)\n";
    const Dog* dog = new Dog();
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();

    std::cout << "\n-- Wrong Animal Test --\n";
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    std::cout << wrong_cat->getType() << " " << std::endl;
    wrong_cat->makeSound();
    wrong_meta->makeSound();

    std::cout << "\n-- TRUE CALL FOR Wrong Animal (STATIC POLYMORPHIZM)  --\n";
    const WrongCat wrong_cat_true;
    std::cout << wrong_cat_true.getType() << " " << std::endl;
    wrong_cat_true.makeSound();

     std::cout << "\n-- TEST FOR Wrong Animal (STATIC POLYMORPHIZM) --\n";
    const WrongCat* wrong_cat_true2 = new WrongCat();
    std::cout << wrong_cat_true2->getType() << " " << std::endl;
    wrong_cat_true2->makeSound();


    delete meta;
    delete j;
    delete i;
    delete dog;
     std::cout << "\n1\n";
    delete wrong_meta;
     std::cout << "\n2\n";
    delete wrong_cat;

     std::cout << "\n3\n";
    delete wrong_cat_true2;
     std::cout << "\n4\n";



return 0;
}
