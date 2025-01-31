CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = harlFilter

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Harl.hpp

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
