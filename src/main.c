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
	if (__init__() == NULL)
		return (84);
	return (0);
}