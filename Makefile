##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

TEST_NAME=	test

INCLUDE	=	include

SRC	=	.//engine_lib/text.c	\
		.//engine_lib/game_events.c	\
		./src/player/player_move.c	\
		./src/player/player_check_interaction.c	\
		./src/player_interaction/interact_obj.c	\
		./src/map_objects/obj_cooldown.c	\
		./src/lib/my_putstr.c	\
		./src/lib/my_strcmp.c	\
		./src/lib/my_strdup.c	\
		./src/lib/my_strlen.c	\
		./src/lib/my_put_nbr.c	\
		./src/spells/spell_manager.c	\
		./src/spells/spell_1_speed.c	\
		.//extern_lib/nxjson.c \
		./src/mobs/mob_mouvement.c	\
		./src/draw/draw_mobs.c	\
		./src/draw/draw_hub.c	\
		./src/draw/shim.c	\
		./src/draw/bar.c	\
		./src/draw/draw_player.c	\
		./src/draw/draw_inventory.c	\
		./src/draw/draw_spell_box.c	\
		./src/json_parser/rpg_json_reader.c	\
		./src/json_parser/rpg_map_json.c	\
		./src/link_list/rpg_init_object_list.c \
		./src/link_list/rpg_inject_object_list.c \
		./src/link_list/rpg_map_init_global.c \
		./src/link_list/rpg_remove_object_list.c \
		./src/inventory/manage_inventory.c	\
		./src/inventory/print_inventory.c	\
		./src/inventory/get_inventory_size.c	\
		./src/inventory/modify_inventory.c	\
		./src/inventory/init_inventory.c	\
		./src//init/init_player.c	\
		./src//init/init.c	\
		./src//event/screen_event.c	\
		./src//event/key_event.c	\
		./src//event/main_event.c	\
		./src/draw/draw_element.c		\
		./src/main.c	\
		./src/ui/draw_ui.c	\
		./src/ui/draw_health.c	\
		./src/ui/info_box.c \
		./src/save_player/rpg_save_player.c \
		./src/spawn_link_list/mob_spawn_init.c \
		./src/spawn_link_list/spawn_mob_init.c \
		./src/spawn_link_list/spawn_mob_inject.c \
		./src/spawn_link_list/spawn_mob_remove.c \
		./src/json_parser/rpg_spawn_json.c \
		./src/destroy/destroy_map.c		\
		./src/mobs_link_list/list_mob_init.c \
		./src/mobs_data_link_list/list_mob_data_init.c \
		./src/mobs_data_link_list/list_mob_data_inject.c \
		./src/mobs_data_link_list/list_mob_data_remove.c \
		./src/mobs_data_link_list/mob_data_list_init.c \
		./src/json_parser/rpg_mob_data_json.c \
		./src/mobs_link_list/list_mob_inject.c \
		./src/start_screen/draw_start_screen.c	\
		./src/start_screen/event_start_screen.c	\
		./src/pause_screen/draw_pause_screen.c	\
		./src/pause_screen/event_pause_screen.c	\
		./src/json_parser/rpg_items_json.c \
		./src/items_data_link_list/init_all_items_data_link_list.c \
		./src/items_data_link_list/items_data_init.c \
		./src/items_data_link_list/items_data_inject.c \

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

all:
		gcc $(CFLAGS) $(SRC) -I./language/us_en/ -c
		gcc $(CFLAGS) *.o -I./language/us_en/ -o $(NAME)

fr:
		gcc $(CFLAGS) $(SRC) -I./language/fr_fr/ -c
		gcc $(CFLAGS) *.o -I./language/fr_fr/ -o $(NAME)

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
