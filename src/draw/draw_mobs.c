/*
** EPITECH PROJECT, 2018
** draw_mobs.c
** File description:
** functiont to draw mobs on map
*/

#include "my_rpg.h"

static void draw_mob_sprite(game_global_t *game, mob_info_t *mob)
{
	sfVector2f pos = {mob->x, mob->y};

	if (mob->id != -1) {
		sfSprite_setPosition(mob->sprite, pos);
		sfRenderWindow_drawSprite(game->window, mob->sprite, NULL);
	}
}

int draw_mobs(game_global_t *game)
{
	mob_info_t *mob = game->mob_deploy->first;

	while (mob) {
		draw_mob_sprite(game, mob);
		mob = mob->next;
	}
	return (0);
}