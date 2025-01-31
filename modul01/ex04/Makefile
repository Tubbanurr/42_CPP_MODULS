CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98

TARGET = replace
SRC = main.cpp Replace.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	@rm -f $(OBJ) $(TARGET)

fclean: clean

re: fclean all
