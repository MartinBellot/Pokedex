##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

D_MY	=	./my

SRC      =      $(D_MY)/my_putstr.c     \
                $(D_MY)/my_str_islower.c        \
                $(D_MY)/my_str_isnum.c  \
                $(D_MY)/my_revstr.c     \
                $(D_MY)/my_str_isprintable.c	\
                $(D_MY)/my_compute_power_rec.c  \
                $(D_MY)/my_showmem.c    \
                $(D_MY)/my_str_isupper.c        \
                $(D_MY)/my_compute_square_root.c        \
                $(D_MY)/my_showstr.c    \
                $(D_MY)/my_strlen.c     \
                $(D_MY)/my_find_prime_sup.c     \
                $(D_MY)/my_sort_int_array.c     \
                $(D_MY)/my_strlowcase.c \
                $(D_MY)/my_getnbr.c     \
                $(D_MY)/my_put_float.c     \
                $(D_MY)/my_strcapitalize.c      \
                $(D_MY)/my_strncat.c    \
                $(D_MY)/my_isneg.c      \
                $(D_MY)/my_strcat.c     \
                $(D_MY)/my_strncmp.c    \
                $(D_MY)/my_is_prime.c   \
                $(D_MY)/my_strcmp.c     \
                $(D_MY)/my_strncpy.c    \
                $(D_MY)/my_strcpy.c     \
                $(D_MY)/my_strstr.c     \
                $(D_MY)/my_putchar.c    \
		$(D_MY)/my_str_to_word_array.c	\
		$(D_MY)/my_strdup.c     \
                $(D_MY)/my_strupcase.c  \
                $(D_MY)/my_put_nbr.c    \
                $(D_MY)/my_str_isalpha.c        \
                $(D_MY)/my_swap.c	\
		$(D_MY)/my_printf.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

HEAD_FILE       =       my.h

MKDIR_INCLUDE   =       mkdir -p

all: $(NAME)

$(NAME):        $(OBJ)
	ar rc ../$(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f $(D_MY)/$(NAME)
