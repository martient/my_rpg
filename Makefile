##
## EPITECH PROJECT, 2017
## matchstick
## File description:
## Makefile
##

NAME	=	my_rpg

TEST_NAME=	test

INCLUDE	=	include

SRC	=	./src/init/init.c		\
		./src/main.c			\
		./extern_lib/nxjson.c

TEST_SRC=	.//my_lib/remove_dup.c	\
		.//my_lib/my_putstr.c	\
		.//my_lib/string_to_word_array.c	\
		.//my_lib/my_strcmp.c	\
		.//my_lib/check_number.c	\
		.//my_lib/my_malloc.c	\
		.//my_lib/my_strdup.c	\
		.//my_lib/my_strlen.c	\
		.//my_lib/array_contains.c	\
		.//my_lib/my_getnbr.c	\
		./src/argv_error.c	\
		./src/help.c	\
		./src/create_int_array.c	\
		./tests/*.c

OBJ	=	$(SRC:.c=.o)

TEST_OBJ=	$(TEST_SRC:.c=.o)

CFLAGS	=	-Wall -pedantic -I./include -I./my_lib -lc_graph_prog

OFLAGS	=	-Wall -pedantic -I./include -I./my_lib -lc_graph_prog

TFLAGS	=	-Wall -pedantic -I./include -I./my_lib --criterion

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all

$(TEST_NAME):	$(TOBJ)
		gcc -c $(TEST_SRC) $(OFLAGS) --coverage
		gcc $(CFLAGS) -lcriterion -lm *.o -o $(TEST_NAME) --coverage

tests_run:	$(TEST_NAME) clean
		rm -f $(TEST_OBJ)
		./test

tests_clean:
		rm *.gc*
		rm $(TEST_NAME)

play:		
		./script.sh $(NAME) 1 > res
