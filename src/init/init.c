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

static player_info_t *init_player(game_global_t *game)
{
	char *file_content = rpg_map_load("./resources/player.json");
	player_info_t *player = malloc(sizeof(player_info_t));
	const nx_json* json = nx_json_parse(file_content, 0);
	sfTexture* texture;
	sfTexture_createFromFile("./resources/sprites/knight.png");
	if (json && player) {
		player->name =  nx_json_get(json, "name")->text_value;
		player->x = nx_json_get(json, "x")->int_value;
		player->y = nx_json_get(json, "y")->int_value;
		player->zone = nx_json_get(json, "zone")->int_value;
		player->health = nx_json_get(json, "pv")->int_value;
		player->mana = nx_json_get(json, "mana")->int_value;
		player->skill_point = nx_json_get(json, "skill_point")->int_value;
		player->rotate = nx_json_get(json, "rotate")->int_value;
		player->cd_q = 0;
		player->cd_w = 0;
		player->cd_e = 0;
		player->cd_r = 0;
		player->cd_a = 0;
		player->sprite = sfSprite_create;
		sfSprite_setTexture(player->sprite, texture, sfTrue);
		game->player = player;
		return (player);
	}
	return (NULL);
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
	if (game->invent == NULL)
		return (NULL);
	if (init_player(game) == NULL)
		return (NULL);
	if (init_engine_ressources(game))
		return (NULL);
	printf("Game finised loading (%lf ms)\n",
	sfClock_getElapsedTime(clock).microseconds * 0.001);
	sfClock_destroy(clock);
	return (game);
}
