/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** This file saved data of player
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "save.h"

void rpg_player_save_phase_5(int fd, int lvl)
{
	write(fd, PLAYER_SAVE_LVL, my_strlen(PLAYER_SAVE_LVL));
	rpg_file_put_nbr(fd, lvl);
	write(fd, PLAYER_SAVE_END, my_strlen(PLAYER_SAVE_END));
}
