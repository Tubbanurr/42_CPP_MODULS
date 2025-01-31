CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = megaphone

all: $(TARGET)

$(TARGET): megaphone.cpp
	@$(CC) $(CFLAGS) -o $(TARGET) megaphone.cpp

clean:
	@rm -f $(TARGET)

fclean: clean

re: fclean all
