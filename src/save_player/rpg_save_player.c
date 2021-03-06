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

void default_save(int fd);

void rpg_player_save_phase_1(int fd, char *name, int x, int y)
{
	write(fd, PLAYER_SAVE_NAME, my_strlen(PLAYER_SAVE_NAME));
	write(fd, name, my_strlen(name));
	write(fd, PLAYER_SAVE_X, my_strlen(PLAYER_SAVE_X));
	rpg_file_put_nbr(fd, x);
	write(fd, PLAYER_SAVE_Y, my_strlen(PLAYER_SAVE_Y));
	rpg_file_put_nbr(fd, y);
}

void rpg_player_save_phase_2(int fd, int health, int max_health,
int mana)
{
	write(fd, PLAYER_SAVE_HEALTH, my_strlen(PLAYER_SAVE_HEALTH));
	rpg_file_put_nbr(fd, health);
	write(fd, PLAYER_SAVE_MAX_HEALTH, my_strlen(PLAYER_SAVE_MAX_HEALTH));
	rpg_file_put_nbr(fd, max_health);
	write(fd, PLAYER_SAVE_MANA, my_strlen(PLAYER_SAVE_MANA));
	rpg_file_put_nbr(fd, mana);
}

void rpg_player_save_phase_3(int fd, int skill_point, int inv_size,
int direction)
{
	write(fd, PLAYER_SAVE_SKILL_POINT, my_strlen(PLAYER_SAVE_SKILL_POINT));
	rpg_file_put_nbr(fd, skill_point);
	write(fd, PLAYER_SAVE_INV_SIZE, my_strlen(PLAYER_SAVE_INV_SIZE));
	rpg_file_put_nbr(fd, inv_size);
	write(fd, PLAYER_SAVE_DIR, my_strlen(PLAYER_SAVE_DIR));
	rpg_file_put_nbr(fd, direction);
}

void rpg_player_save_phase_4(int fd, int zone, int quest_id, float xp)
{
	write(fd, PLAYER_SAVE_Q_ID, my_strlen(PLAYER_SAVE_Q_ID));
	rpg_file_put_nbr(fd, quest_id);
	write(fd, PLAYER_SAVE_XP, my_strlen(PLAYER_SAVE_XP));
	rpg_file_put_nbr(fd, (int)xp);
	write(fd, PLAYER_SAVE_ZONE, my_strlen(PLAYER_SAVE_ZONE));
	rpg_file_put_nbr(fd, zone);
}

int rpg_player_save(player_info_t *player)
{
	int fd = 0;

	fd = open(PLAYER_SAVE_FILE, O_WRONLY | O_CREAT, 0666);
	if (player) {
		rpg_player_save_phase_1(fd, player->name, player->x,
		player->y);
		rpg_player_save_phase_2(fd, player->health, player->max_health,
		player->mana);
		rpg_player_save_phase_3(fd, player->skill_point,
		1, player->direction);
		rpg_player_save_phase_4(fd, player->zone,
		player->current_quest_id, player->xp);
		rpg_player_save_phase_5(fd, player->level);
	} else {
		default_save(fd);
	}
	close(fd);
	return (0);
}
