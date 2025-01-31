#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <limits>

class Zombie {

private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
    void setName(const std::string& name);

};

Zombie* zombieHorde(int N, std::string* names);

#endif
