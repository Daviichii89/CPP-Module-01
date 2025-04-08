#Config
CC = c++
TARGET = zombie
CFLAGS = -Wall -Wextra -Werror -std=c++98
# DFLAGS = -fsanitize=address

# Directory
SRC = Zombie.cpp randomChump.cpp main.cpp newZombie.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re