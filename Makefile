##
## EPITECH PROJECT, 2022
## BlueLock
## File description:
## BlueLock
##

CC 		= gcc
SRC 	= $(wildcard src/*.c)
FLAGS 	= -Wall -Wextra -Werror -I./include
BFLAGS 	= -lbluetooth
NAME 	= BlueLock

all: $(NAME)

$(NAME): clean
		$(CC) $(SRC) -o $(NAME) $(FLAGS) $(BFLAGS)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
