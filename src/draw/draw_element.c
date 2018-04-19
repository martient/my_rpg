/*
** EPITECH PROJECT, 2018
** draw_element.c
** File description:
** function to draw element
*/

#include "my_rpg.h"

int draw_z(game_global_t *game, object_info_t *tile, int z)
{
	sfSprite *sprite;
	sfVector2f pos = {tile->x * 32, tile->y * 32};

	if (tile->z == z && tile->visible == 0) {
		sprite = sfSprite_create();
		sfSprite_setPosition(sprite, pos);
		sfSprite_setTexture(sprite, tile->texture, sfTrue);
		sfRenderWindow_drawSprite(game->window, sprite, NULL);
		sfSprite_destroy(sprite);
	}
	return (0);
}

int draw_element(game_global_t *game)
{
	object_info_t *map = game->info_map->first->first;
	object_info_t *bck_map = map;
	int player = 0;

	for (int i = -1; i < 5; i++) {
		if (i == 1 && player== 0) {
			draw_player(game);
			player = 1;
		}
		map = bck_map;
		while (map) {
			draw_z(game, map, i);
			map = map->next;
		}
	}
	return (0);
}