/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/
#include "my_rpg.h"

void game_loop(game_global_t *game)
{
	only_play(game, "main_music");
	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		analyse_event(game);
		draw__(game);
	}
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
