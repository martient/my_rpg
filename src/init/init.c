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
	sfVideoMode mode = {800, 600, 32};

	window = sfRenderWindow_create(mode, GAME_NAME,
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, game->frame_rate);
	game->window = window;
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

static player_info_t *init_player(void)
{
	player_info_t *player = malloc(sizeof(player_info_t));

	if (player == NULL)
		return (NULL);
	player->name = "Player";
	player->x = 0;
	player->y = 0;
	player->zone = 0;
	return (player);
}

game_global_t *__init__(void)
{
	sfClock *clock = sfClock_create();
	game_global_t *game = malloc(sizeof(game_global_t));
	player_info_t *player = NULL;

	if (game == NULL)
		return (NULL);
	init_game(game);
	init_screen(game);
	player = init_player();
	if (player == NULL)
		return (NULL);
	else
		game->player = player;
	if (init_engine_ressources(game))
		return (NULL);
	printf("Game finised loading (%lf ms)\n",
	sfClock_getElapsedTime(clock).microseconds * 0.001);
	sfClock_destroy(clock);
	return (game);
}