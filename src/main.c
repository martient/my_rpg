/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my_rpg.h"

int main(int ac, char *argv[], char *env[])
{
	game_global_t *game = __init__();

	if (game == NULL)
		return (84);
	free(game->player);
	sfRenderWindow_destroy(game->window);
	free(game);
	return (0);
}