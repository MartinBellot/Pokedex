##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile graphic
##

SRC = 	src/*.c \
		src/parsing/*.c

OBJ = *.o

NAME = searchbar

LIB_PATH = lib/my/

LIB_NAME = my

INCLUDE_PATH = includes/

CFLAGS = -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lm -g


all:
	make -C $(LIB_PATH)
	gcc -c $(SRC) -I $(INCLUDE_PATH) -Wall -Wextra
	gcc $(OBJ) -L $(LIB_PATH) -l$(LIB_NAME) -o $(NAME) $(CFLAGS)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all
