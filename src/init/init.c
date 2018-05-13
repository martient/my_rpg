/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** functions to init window
*/

#include "my_rpg.h"

static void init_screen(game_global_t *game)
{
	sfRenderWindow *window;
	sfClock *clock = sfClock_create();
	sfVideoMode mode = {800, 600, 32};

	window = sfRenderWindow_create(mode, GAME_NAME,
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, game->frame_rate);
	game->window = window;
	game->clock = clock;
	game->width = 800;
	game->height = 600;
	game->inventory_show = 0;
	game->skill_tree_show = 0;
	game->zoom = 1;
}

static void init_game(game_global_t *game)
{
	game->frame_rate = DEFAULT_FRAME_RATE;
}

game_global_t *__init__(void)
{
	game_global_t *game = malloc(sizeof(game_global_t));

	if (game == NULL)
		return (NULL);
	game->state = 0;
	init_game(game);
	init_screen(game);
	game->invent = init_inventory();
	game->tree = init_skill_tree();
	if (init_game_data(game) == -1)
		return (NULL);
	return (game);
}
