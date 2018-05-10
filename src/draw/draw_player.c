/*
** EPITECH PROJECT, 2018
** draw_player.c
** File description:
** function to draw player with its camera
*/

#include "my_rpg.h"

void draw_player(game_global_t *game)
{
	static int anim = 0;
	int dir = (game->player->direction - 1) * 39;
	sfIntRect animation = {(anim * 39), dir, 39, 39};
	sfVector2f pos = {game->player->x, game->player->y};
	sfTexture *texture = game->player->texture;

	sfSprite_setTexture(game->player->sprite, texture, sfTrue);
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
	// player_cam(game);
}