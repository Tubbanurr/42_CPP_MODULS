CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex01
SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Span.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
