##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##


SRC_FILES	=	./src

SRC	=	$(SRC_FILES)/main.c

LIB	=	-L. -lmy

OBJ	=	$(SRC:.c=.o)

NAME    =       my_pokedex

HEAD_FILE	=	includes/my.h

CFLAGS  =       -W -Wall -Wextra -I includes/ -lm

CSFML	=	-lcsfml-system -lcsfml-window -lcsfml-audio -lcsfml-graphics

all:	$(OBJ)
	$(MAKE) -C lib/
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(CSFML)

clean:
	rm -f *log
	rm -f *~
	rm -f $(OBJ)
	rm -f $(SRC_FILES)/$(OBJ)
	rm -f libstat.a
	rm -f libmy.a
	rm -f liblist.a
	rm -f lib/my/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
