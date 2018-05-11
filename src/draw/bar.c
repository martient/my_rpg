/*
** EPITECH PROJECT, 2018
** bar.c
** File description:
** function to draw info bar
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

static int get_bar_size(int max, int percentage)
{
	int val;

	val = (percentage * max) / 100;
	return (val);
}

static void bar_destroy(sfUint8 *pixels_front, sfUint8 *pixels_back,
sfTexture *bar_texture, sfSprite *bar_sprite)
{
	free(pixels_front);
	free(pixels_back);
	sfSprite_destroy(bar_sprite);
	sfTexture_destroy(bar_texture);
}

// INFO:
// 0 width
// 1 height
// 2
void draw_bar(game_global_t *game, sfColor colors[2], int *infos)
{
	int front_width = get_bar_size(infos[0], infos[2]);
	sfUint8 *pixels_back = malloc(infos[0] * infos[1] * 4);
	sfUint8 *pixels_front = malloc(front_width * infos[1] * 4);
	sfTexture *bar_texture = sfTexture_create(infos[0], infos[1]);
	sfSprite *bar_sprite = sfSprite_create();
	sfVector2f pos = {infos[3], infos[4]};

	if (pixels_front == NULL || pixels_back == NULL)
		engine_exit(game);
	color_bar(pixels_back, colors[0], infos[0], infos[1]);
	color_bar(pixels_front, colors[1], front_width, infos[1]);
	sfTexture_updateFromPixels(bar_texture,
	pixels_back, infos[0], infos[1], 0, 0);
	sfTexture_updateFromPixels(bar_texture,
	pixels_front, front_width, infos[1], 0, 0);
	sfSprite_setTexture(bar_sprite, bar_texture, sfTrue);
	sfSprite_setPosition(bar_sprite, pos);
	sfRenderWindow_drawSprite(game->window, bar_sprite, NULL);
	bar_destroy(pixels_front, pixels_back, bar_texture, bar_sprite);
}