#Config
CC = c++
NAME = harl
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -fsanitize=address

# Directory
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re