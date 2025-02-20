CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = MutantStack.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
