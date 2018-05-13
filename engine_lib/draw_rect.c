/*
** EPITECH PROJECT, 2018
** draw_rect.c
** File description:
** function to draw rect
*/

#include "my_rpg.h"

static int color_bar(sfUint8 *pixels, sfColor color, int width, int height)
{
	if (pixels == NULL)
		return (1);
	for (int i = 0; i < width*height*4; i+= 4) {
		pixels[i] = color.r;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.b;
		pixels[i + 3] = color.a;
	}
	return (0);
}

void draw_rect(game_global_t *game, int infos[4], sfColor color)
{
	sfUint8 *pixels_back = malloc(infos[0] * infos[1] * 4);
	sfTexture *bar_texture = sfTexture_create(infos[0], infos[1]);
	sfSprite *bar_sprite = sfSprite_create();
	sfVector2f pos = {infos[3], infos[4]};

	if (pixels_back == NULL)
		engine_exit(game);
	color_bar(pixels_back, color, infos[0], infos[1]);
	sfTexture_updateFromPixels(
	bar_texture, pixels_back, infos[0], infos[1], 0, 0);
	sfSprite_setTexture(bar_sprite, bar_texture, sfTrue);
	sfSprite_setPosition(bar_sprite, pos);
	sfRenderWindow_drawSprite(game->window, bar_sprite, NULL);
	free(pixels_back);
	sfSprite_destroy(bar_sprite);
	sfTexture_destroy(bar_texture);
}