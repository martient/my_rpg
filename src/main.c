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

void game_loop(game_global_t *game)
{
	sfClock *draw_clock = sfClock_create();

	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
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