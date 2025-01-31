CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = main.o Zombie.o zombieHorde.o

all: ZombieProgram

ZombieProgram: $(OBJ)
	$(CXX) $(CXXFLAGS) -o ZombieProgram $(OBJ)

main.o: main.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Zombie.o: Zombie.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c Zombie.cpp

zombieHorde.o: zombieHorde.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c zombieHorde.cpp

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ZombieProgram

re: fclean all
