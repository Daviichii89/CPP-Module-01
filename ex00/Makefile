

#Config
CC = c++
TARGET = Zombies
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -fsanitize=address

# Directory
SRC = Zombies.cpp randomChump.cpp main.cpp \
		newZombie.cpp

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CC) $(CFLAGS) $(DFLAGS) $(SRC) -o $(TARGET)

clean: 

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re