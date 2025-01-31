#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        std::string str;

        for (int i = 1; i < ac; i++)
        {
            str = av[i];
            for (int j = 0; j < (int)str.length(); j++)
                std::cout << (char)toupper(str[j]);
            if (i < ac - 1)
                std::cout << " ";
            else
                std::cout << std::endl;
        }
    }
    return 0;
}
