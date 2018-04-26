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
	int i = 0;

	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		analyse_event(game);
		if (sfClock_getElapsedTime(draw_clock).microseconds / 1000000.0 > 0.1) {
			draw__(game);
			sfClock_restart(draw_clock);
		}
		if (i++ == 0)
			rpg_mob_generator(game->mob_spawn, game->mob_data, game->mob_deploy, game->player);
	}
	sfClock_destroy(draw_clock);
}

int main(int ac, char *argv[], char *env[])
{
	game_global_t *game = __init__();

	if (game == NULL)
		return (84);
	srand(time(NULL));
	if (ac > 1)
		game_loop(game);
	else
		start_game_loop(game);
	free(game->player);
	destroy_map(game);
	sfRenderWindow_destroy(game->window);
	free(game);
	return (0);
}
