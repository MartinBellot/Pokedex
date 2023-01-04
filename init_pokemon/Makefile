##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##
SRC	=	src/main.c \
		src/parse_file.c \
		src/init_pokemons.c \
		src/get_line_info.c \
		src/destroy_poke_data.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

LDFLAGS	=	-L./lib/ -l:libw_csfml.a -L./lib/ \
			-l:libw_printf.a -L./lib/ -l:libtools.a

CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

NAME	=	init_pokemon

all:	$(NAME)

$(NAME):	make_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFMLFLAGS) -lm

make_lib:
	make -C lib/tools/
	make -C lib/w_printf/
	make -C lib/w_csfml/

clean:
	rm -f *~
	rm -f src/*~ src/*.o

fclean : clean
	rm -f $(NAME)
	make fclean -C lib/tools/
	make fclean -C lib/w_printf/
	make fclean -C lib/w_csfml

re:	fclean all
