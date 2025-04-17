#Config
CC = c++
TARGET = replace_text
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -fsanitize=address

# Directory
SRC = main.cpp 
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