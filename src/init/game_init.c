/*
** EPITECH PROJECT, 2018
** game_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

static int init_engine_ressources(game_global_t *game)
{
	sfFont *engine_font;
	engine_font = sfFont_createFromFile("./resources/arial.ttf");
	if (engine_font == NULL)
		return (1);
	game->font = engine_font;
	return (0);
}

static int init_game_data_bis(game_global_t *game)
{
	if (rpg_spawn_init_list(game->mob_spawn) == -1)
		return (-1);
	game->mob_deploy = rpg_mob_init();
	game->mob_data = rpg_mob_data_init();
	if (rpg_json_init_mob_data(game->mob_data) == -1)
		return (-1);
	game->items_data = rpg_items_data_init();
	if (rpg_init_link_list_items_data(game->items_data) == -1)
		return (-1);
	if (init_sound(game))
		return (-1);
	rpg_json_init_inventory_data(game);
	return (0);
}

int init_game_data(game_global_t *game)
{
	if (game->invent == NULL)
		return (-1);
	if (init_player(game) == NULL)
		return (-1);
	if (init_engine_ressources(game))
		return (-1);
	game->info_map = rpg_map_info();
	if (rpg_init_global_info(game->info_map->first) == 0)
		return (-1);
	game->mob_spawn = rpg_spawn_init();
	return (init_game_data_bis(game));
}
