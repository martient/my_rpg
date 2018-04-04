##
## EPITECH PROJECT, 2017
## matchstick
## File description:
## Makefile
##

NAME	=	my_rpg

TEST_NAME=	test

INCLUDE	=	include

SRC	=	.//engine_lib/text.c	\
		.//engine_lib/game_events.c	\
		.//billow/my_putstr.c	\
		.//billow/my_strcmp.c	\
		.//billow/my_strdup.c	\
		.//billow/my_strlen.c	\
		.//billow/my_put_nbr.c	\
		.//extern_lib/nxjson.c \
		./src//draw/draw_hub.c	\
		./src//draw/shim.c	\
		./src//draw/bar.c	\
		./src//draw/draw_player.c	\
		./src//json_parser/rpg_json_reader.c	\
		./src//json_parser/rpg_map_json.c	\
		./src//inventory/manage_inventory.c	\
		./src//inventory/print_inventory.c	\
		./src//inventory/get_inventory_size.c	\
		./src//inventory/modify_inventory.c	\
		./src//inventory/init_inventory.c	\
		./src//init/init_player.c	\
		./src//init/init.c	\
		./src//event/screen_event.c	\
		./src//event/key_event.c	\
		./src//event/main_event.c	\
		./src/main.c	\


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

CFLAGS	=	-Wall -pedantic -I./include -I./my_lib -lc_graph_prog -g3

OFLAGS	=	-Wall -pedantic -I./include -I./my_lib -lc_graph_prog -g3

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
