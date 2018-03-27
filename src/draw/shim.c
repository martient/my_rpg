/*
** EPITECH PROJECT, 2018
** shim.c
** File description:
** draw a shim
*/

#include "my_rpg.h"

static int color_shim(sfUint8 *pixels, sfColor color)
{
	for (int i = 0; i < 800*600*4; i+= 4) {
		pixels[i] = color.r;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.b;
		pixels[i + 3] = 100;
	}
}
void draw_shim(game_global_t *game, sfColor color)
{
	sfUint8 *pixels = malloc(800 * 600 * 4);
	sfTexture *shim_texture = sfTexture_create(800, 600);
	sfSprite *shim_sprite = sfSprite_create();

	if (pixels == NULL)
		engine_exit(game);
	color_shim(pixels, color);
	sfTexture_updateFromPixels(shim_texture, pixels, 800, 600, 0, 0);
	sfSprite_setTexture(shim_sprite, shim_texture, sfTrue);
	sfRenderWindow_drawSprite(game->window, shim_sprite, NULL);
	free(pixels);
}