/*
** EPITECH PROJECT, 2018
** draw_start_screen.c
** File description:
** function to draw start screen
*/

#include "my_rpg.h"

int draw_start_button(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f scale = {2 * (game->width / 800), 2};
	sfVector2f position = {game->width / 2 - (54 * scale.x), game->height / 2};

	texture = sfTexture_createFromFile("./resources/ui/start_btn.png", NULL);
	sprite = sfSprite_create();
	if (sprite == NULL)
		return (1);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, position);
	sfSprite_setScale(sprite, scale);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	return (0);
}

void draw_start_screen(game_global_t *game)
{
	int info[3] = {(game->width / 2) - ((my_strlen(GAME_NAME) / 4) * 36),
	(game->height / 2) - 150, 36};

	sfRenderWindow_clear(game->window, sfWhite);
	engine_create_text(game, GAME_NAME, info, sfRed);
	draw_start_button(game);
	sfRenderWindow_display(game->window);
}

void start_game_loop(game_global_t *game)
{
	sfClock *draw_clock = sfClock_create();

	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		event_start_screen(game);
		if (sfClock_getElapsedTime(draw_clock).microseconds / 1000000.0 > 0.1) {
			draw_start_screen(game);
			sfClock_restart(draw_clock);
		}
	}
	sfClock_destroy(draw_clock);
}