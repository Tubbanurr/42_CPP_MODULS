CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = violence

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
