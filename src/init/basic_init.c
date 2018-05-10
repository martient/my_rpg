/*
** EPITECH PROJECT, 2018
** basic_init.c
** File description:
** Function that sets the basic values of the player
*/

#include "player.h"

void basic_init(player_info_t *player)
{
	player->spell_cd[0] = 0;
	player->spell_cd[1] = 0;
	player->spell_cd[2] = 0;
	player->spell_cd[3] = 0;
	player->spell_cd[4] = 0;
	player->spell_duration[0] = 0;
	player->spell_duration[1] = 0;
	player->spell_duration[2] = 0;
	player->spell_duration[3] = 0;
	player->spell_duration[4] = 0;
	player->speed = 1;
	player->power = 1;
}