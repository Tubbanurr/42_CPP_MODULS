#include "Zombie.hpp"

int main() {
    int N;
    std::string name;

    std::cout << "Enter the number of zombies: ";
    std::cin >> N;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string* names = new std::string[N];

    for (int i = 0; i < N; ++i) {
        std::cout << "Enter the name for zombie " << (i + 1) << ": ";
        std::getline(std::cin, names[i]);
    }

    Zombie* horde = zombieHorde(N, names);

    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    delete[] names;
    delete[] horde;

    return 0;
}
