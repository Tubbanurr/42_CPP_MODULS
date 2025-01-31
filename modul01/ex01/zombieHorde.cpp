#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string* names)
{
    if (N <= 0)
        return 0;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; ++i)
        new(&horde[i]) Zombie(names[i]);

    return horde;
}
