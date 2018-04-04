/*
** EPITECH PROJECT, 2018
** draw_player.c
** File description:
** function to draw player with its camera
*/

#include "my_rpg.h"

static void player_cam(game_global_t *game)
{
	sfVector2f pos = {game->player->x + (39/2), game->player->y + (39/2)};
	sfFloatRect cam = {0, 0, game->width, game->height};

	game->player->camera =  sfView_createFromRect(cam);
	sfView_setCenter(game->player->camera, pos);
	sfRenderWindow_setView(game->window, game->player->camera);
}

void draw_player(game_global_t *game)
{
	static int anim = 0;
	sfIntRect animation = {(anim * 39), (game->player->direction - 1) * 39, 39, 39};
	sfVector2f pos = {game->player->x, game->player->y};

	sfSprite_setTexture(game->player->sprite, game->player->texture, sfTrue);
	sfSprite_setTextureRect(game->player->sprite, animation);
	sfSprite_setPosition(game->player->sprite, pos);
	sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
	if (game->player->moving)
		anim++;
	else
		anim = 1;
	if (anim > 2)
		anim = 0;
	game->player->moving = 0;
	player_cam(game);
}