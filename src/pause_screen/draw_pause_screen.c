/*
** EPITECH PROJECT, 2018
** draw_pause_screen.c
** File description:
** function to draw pause screen
*/

#include "my_rpg.h"

int draw_play_button(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	// sfVector2f scale = {2 * (game->width / 800), 2};
	sfVector2f position = {game->width / 2, game->height / 2};

	texture = sfTexture_createFromFile("./resources/ui/start_btn.png", NULL);
	sprite = sfSprite_create();
	if (sprite == NULL)
		return (1);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, position);
	// sfSprite_setScale(sprite, scale);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	return (0);
}

int draw_pause_screen(game_global_t *game)
{

	float x = (float)game->width / 2;
	float y = (float)game->height / 2;
	int info[3] = {x, y, 32};

	printf("W:%d H:%d %d:%d\n", game->width, game->height, info[0], info[1]);
	sfRenderWindow_clear(game->window, sfWhite);
	// engine_create_text(game, "PAUSE", info, sfRed);
	draw_play_button(game);
	sfRenderWindow_display(game->window);
	return (0);
}

void pause_screen(game_global_t *game)
{
	sfClock *draw_clock = sfClock_create();

	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		event_pause_screen(game);
		if (sfClock_getElapsedTime(draw_clock).microseconds / 1000000.0 > 0.1) {
			draw_pause_screen(game);
			sfClock_restart(draw_clock);
		}
	}
	sfClock_destroy(draw_clock);
}