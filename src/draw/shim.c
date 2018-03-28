/*
** EPITECH PROJECT, 2018
** shim.c
** File description:
** draw a shim
*/

#include "my_rpg.h"

/*
** Needs to be improved to work with all window sizes
*/

static int color_shim(sfUint8 *pixels, sfColor color)
{
	if (pixels == NULL)
		return (1);
	for (int i = 0; i < 800*600*4; i+= 4) {
		pixels[i] = color.r;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.b;
		pixels[i + 3] = 100;
	}
	return (0);
}
void draw_shim(game_global_t *game, sfColor color)
{
	sfUint8 *pixels = malloc(800 * 600 * 4);
	sfTexture *shim_texture = sfTexture_create(800, 600);
	sfSprite *shim_sprite = sfSprite_create();

	if (pixels == NULL)
		engine_exit(game);
	if (color_shim(pixels, color))
		engine_exit(game);
	sfTexture_updateFromPixels(shim_texture, pixels, 800, 600, 0, 0);
	sfSprite_setTexture(shim_sprite, shim_texture, sfTrue);
	sfRenderWindow_drawSprite(game->window, shim_sprite, NULL);
	free(pixels);
	sfSprite_destroy(shim_sprite);
	sfTexture_destroy(shim_texture);
}