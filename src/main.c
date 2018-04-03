/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my_rpg.h"


int draw(game_global_t *game, int *infos, int *infos2)
{
	if (game->state != 0)
		return (0);
	sfColor colors[2] = {sfRed, sfGreen};
	sfColor colors2[2] = {sfBlack, sfBlue};
	draw_bar(game, colors, infos);
	draw_bar(game, colors2, infos2);
	sfRenderWindow_display(game->window);
	infos[2] -= 5;
	if (infos[2] >= 5)
		infos[2] -= 5;
	else
		infos[2] = 100;
	return (0);
}

void update_screen_size(game_global_t *game)
{
	sfVector2u screen_size;

	screen_size = sfRenderWindow_getSize(game->window);
	game->width = screen_size.x;
	game->height = screen_size.y;
}

int analyse_event(game_global_t *game)
{
	sfEvent event;
	double delta_time =
	sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game->window);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
	}
	if (sfKeyboard_isKeyPressed(sfKeyW)) {
		game->player->y -= 1 * (delta_time);
	}
	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		game->player->y += 1 * delta_time;
	}
	if (sfKeyboard_isKeyPressed(sfKeyA)) {
		game->player->x -= 1 * delta_time;
	}
	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		game->player->x += 1 * delta_time;
	}
	sfClock_restart(game->clock);
	return (0);
}

void draw__(game_global_t *game)
{
	printf("X:%d; Y:%d\n", game->width, game->height);
}

void game_loop(game_global_t *game)
{
	sfClock *draw_clock = sfClock_create();

	sfRenderWindow_setFramerateLimit(game->window, 10);
	while (sfRenderWindow_isOpen(game->window)) {
		analyse_event(game);
		if (sfClock_getElapsedTime(draw_clock).microseconds / 1000000.0 > 0.1) {
			draw__(game);
			sfClock_restart(draw_clock);
		}
	}
	sfClock_destroy(draw_clock);
}

int main(int ac, char *argv[], char *env[])
{
	game_global_t *game = __init__();

	if (game == NULL)
		return (84);
	game_loop(game);
	free(game->player);
	sfRenderWindow_destroy(game->window);
	free(game);
	return (0);
}