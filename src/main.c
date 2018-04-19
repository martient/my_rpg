/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/
#include "my_rpg.h"

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
	srand(time(NULL));
	game_loop(game);
	free(game->player);
	destroy_map(game);
	sfRenderWindow_destroy(game->window);
	free(game);
	return (0);
}