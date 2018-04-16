/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** This file saved data of player
*/

#include "my_rpg.h"

static int rpg_player_save_fd(void)
{
	int *fd = 0;

	fd = open("resources/player.json", O_WRONLY | O_CREAT);
	return (fd);
}

int rpg_player_save(player_info_t *player)
{
	int fd = 0;

	if (!player)
		return 84;
	fd = rpg_player_save_fd();
	write(fd, "{\n\t\"name\": \"" , my_strlen("{\n\t\"name\":·\""));
	write(fd, player->name, my_strlen(player->name));
	write(fd, "\",\n\t\"x\": \"", my_strlen("\",\n\t\"x\": \""));
	my_put_nbr(int(player->x));
	write(fd, "\",\n\t\"y\": \"",·my_strlen("\",\n\t\"y\": \""));
	my_put_nbr(int(player->y));
	write(fd, "\",\n\t\"health\": \"",·my_strlen("\",\n\t\"health\": \""));
	my_put_nbr(player->health);
	write(fd, "\",\n\t\"max_health\": \"",
	      ·my_strlen("\",\n\t\"max_health\": \""));
	my_put_nbr(player->max_health);
	write(fd, "\",\n\t\"mana\": \"",·my_strlen("\",\n\t\"mana\": \""));
	my_put_nbr(player->mana);
	write(fd, "\",\n\t\"skill_point\": \"",
	      ·my_strlen("\",\n\t\"skill_point\": \""));
	my_put_nbr(player->skill_point);
	write(fd, "\",\n\t\"inv_size\": \"",
	      ·my_strlen("\",\n\t\"inv_size\": \""));
	my_put_nbr(player->inv_size);
	write(fd, "\",\n\t\"direction\": \"",
	      ·my_strlen("\",\n\t\"direction\": \""));
	my_put_nbr(player->direction);
	write(fd, "\",\n\t\"zone\": \"",·my_strlen("\",\n\t\"zone\": \""));
	my_put_nbr(player->zone);
	write(fd, "\n}" , my_strlen("\n}"));
	close(fd);
	return (0);
}
