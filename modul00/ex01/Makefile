FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

RM = rm -f

NAME = phonebook

SRC =  phoneBook.cpp contact.cpp main.cpp 

OBJ = $(SRC:.cpp=.o)

HEADERS = phoneBook.hpp contact.hpp
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(OBJ) $(NAME)

re : fclean all
