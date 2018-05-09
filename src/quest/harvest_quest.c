/*
** EPITECH PROJECT, 2018
** harvest_quest.c
** File description:
** function for handling harvest quest
*/

#include "my_rpg.h"

int is_harvest_done(game_global_t *game)
{
	printf("Checking harvest_qust\n");
	printf("Current status: %d, %d, %d\n",
	get_item_quantity(game, "Carrots"),
	get_item_quantity(game, "Mushrooms"),
	get_item_quantity(game, "Egg Plant"));
	if (get_item_quantity(game, "Carrots") < 5)
		return (1);
	if (get_item_quantity(game, "Mushrooms") < 2)
		return (1);
	if (get_item_quantity(game, "Egg Plant") < 3)
		return (1);
	play_sound(game, "success");
	printf("Quest Done\n");
	return (0);
}