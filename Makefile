##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##


SRC_FILES	=	./src

SPRITES =       ./sprites

EVENTS	=	./events

BUTTONS	=	./buttons

MUSIC	=	./music

SRC	=	$(SRC_FILES)/main.c     \
		$(SRC_FILES)/animation.c     \
        $(SRC_FILES)/$(SPRITES)/pokedex.c	\
		$(SRC_FILES)/$(SPRITES)/artwork.c	\
		$(SRC_FILES)/$(BUTTONS)/init_buttons.c	\
		$(SRC_FILES)/$(BUTTONS)/handle_buttons.c	\
		$(SRC_FILES)/$(EVENTS)/game_events.c	\
		$(SRC_FILES)/$(MUSIC)/upload_music.c	\

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
	rm -f libmy.a
	rm -f lib/my/*.o
	$(MAKE) -C searchbar/ clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C searchbar/ fclean

re: fclean all

.PHONY: all clean fclean re
