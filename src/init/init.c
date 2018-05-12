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
	game->zoom = 1;
}

static int init_engine_ressources(game_global_t *game)
{
	sfFont *engine_font;
	engine_font = sfFont_createFromFile("./resources/arial.ttf");
	if (engine_font == NULL)
		return (1);
	game->font = engine_font;
	return (0);
}

static void init_game(game_global_t *game)
{
	game->frame_rate = DEFAULT_FRAME_RATE;
}

game_global_t *__init__(void)
{
	sfClock *clock = sfClock_create();
	game_global_t *game = malloc(sizeof(game_global_t));

	if (game == NULL)
		return (NULL);
	game->state = 0;
	init_game(game);
	init_screen(game);
	game->invent = init_inventory();
	game->tree = init_skill_tree();
	if (game->invent == NULL)
		return (NULL);
	if (init_player(game) == NULL)
		return (NULL);
	if (init_engine_ressources(game))
		return (NULL);
	game->info_map = rpg_map_info();
	if (rpg_init_global_info(game->info_map->first) == 0)
		return (NULL);
	game->mob_spawn = rpg_spawn_init();
	if (rpg_spawn_init_list(game->mob_spawn) == -1)
		return (NULL);
	game->mob_deploy = rpg_mob_init();
	game->mob_data = rpg_mob_data_init();
	if (rpg_json_init_mob_data(game->mob_data) == -1)
		return (NULL);
	game->items_data = rpg_items_data_init();
	if (rpg_init_link_list_items_data(game->items_data) == -1)
		return (NULL);
	if (init_sound(game))
		return (NULL);
	rpg_json_init_inventory_data(game);
	printf("Game finised loading (%lf ms)\n",
	sfClock_getElapsedTime(clock).microseconds * 0.001);
	sfClock_destroy(clock);
	return (game);
}
