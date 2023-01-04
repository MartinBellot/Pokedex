##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile My LIB
##

SRC = *.c

OBJ = *.o

NAME = libmy.a

HEAD_FILE = *.h

all:
	gcc -c *.c -Wall -Wextra
	ar rc $(NAME) *.o
	cp $(HEAD_FILE) ../../includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
