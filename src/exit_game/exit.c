/*
** EPITECH PROJECT, 2018
** exit.c
** File description:
** function for when exiting game
*/

#include "my_rpg.h"

void exit_game(game_global_t *game)
{
	rpg_player_save(game->player);
	rpg_inventory_save(game->invent);
	rpg_mob_data_remove_all(game->mob_data);
	destroy_sound(game);
	sfRenderWindow_close(game->window);
}
