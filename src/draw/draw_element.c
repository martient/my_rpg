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

	// printf("TileZ: %d (%d)\n", tile->z, z);
	if (tile->z == z) {
		sprite = sfSprite_create();
		sfSprite_setPosition(sprite, pos);
		sfSprite_setTexture(sprite, tile->texture, sfTrue);
		sfRenderWindow_drawSprite(game->window, sprite, NULL);
	}
	return (0);
}

int draw_element(game_global_t *game)
{
	object_info_t *map = game->info_map->first->first;
	int player = 0;

	for (int i = 0; i < Z_MAXIMUM; i++) {
		//printf("Drawing (z:%d)\n", i);
		if (i == 1 && player== 0) {
			draw_player(game);
			player = 1;
		}	
		while (map) {
			draw_z(game, map, i);
			map = map->next;
		}
	}
	return (0);
}