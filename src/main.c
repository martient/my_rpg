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
	// for (int i = 0; i < 3; i++)
	// 	rpg_mob_generator(game->mob_spawn, game->mob_data,
	// 	game->mob_deploy, game->player);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		analyse_event(game);
		rpg_mob_generator(game->mob_spawn, game->mob_data,
		game->mob_deploy, game->player);
		draw__(game);
	}
}

int main(int ac, char *argv[], char *env[])
{
	game_global_t *game = __init__();

	if (game == NULL)
		return (84);
	srand(time(NULL));
	start_game_loop(game);
	free(game->player);
	destroy_map(game);
	sfRenderWindow_destroy(game->window);
	free(game);
	return (0);
}
