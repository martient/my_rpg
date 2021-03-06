/*
** EPITECH PROJECT, 2018
** init_player.c
** File description:
** funciton to initialise player
*/

#include "my_rpg.h"

static void init_player_sprite(player_info_t *player)
{
	sfTexture *player_texture;
	sfSprite *player_sprite;
	sfIntRect spritesheet_rect = {0, 0, 32, 32};
	sfVector2f pos = {player->x, player->y};
	char *path = my_strdup("./resources/sprites/knight.png");

	player_texture = sfTexture_createFromFile(path, NULL);
	player_sprite = sfSprite_create();
	sfSprite_setTexture(player_sprite, player_texture, sfTrue);
	sfSprite_setTextureRect(player_sprite, spritesheet_rect);
	sfSprite_setPosition(player_sprite, pos);
	player->sprite = player_sprite;
	player->texture = player_texture;
	player->moving = 0;
	free(path);
}

static void init_player_camera(game_global_t *game, player_info_t *player)
{
	sfView *player_camera;
	int len1 = (player->x - (game->width / 2));
	sfVector2f pos = {len1, player->y - (game->height / 2)};
	sfFloatRect cam = {game->width, game->height};

	player_camera = sfView_createFromRect(cam);
	sfView_setCenter(player_camera, pos);
	player->camera = player_camera;
}

static player_info_t *init_player_event(player_info_t *player)
{
	interaction_event_t *event = malloc(sizeof(interaction_event_t));

	if (event == NULL)
		return (NULL);
	event->type = 0;
	event->obj = NULL;
	player->event = event;
	player->state = 0;
	return (player);
}

player_info_t *init_player(game_global_t *game)
{
	char *file_content = rpg_player_load("./resources/player.json");
	player_info_t *player = malloc(sizeof(player_info_t));
	const nx_json* json = nx_json_parse(file_content, 0);

	if (json && player) {
		saved_init(player, json);
		basic_init(player);
		player->xp = 0.0;
		init_player_sprite(player);
		init_player_camera(game, player);
		if (init_player_event(player) == NULL)
			return (NULL);
		game->player = player;
		return (player);
	}
	return (NULL);
}
