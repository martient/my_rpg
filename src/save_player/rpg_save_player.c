/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** This file saved data of player
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my_rpg.h"

static int rpg_file_put_nbr(int fd, int nb)
{
	int val = 0;

	if (nb < 0) {
		write(fd, "-", 1);
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9) {
		val = nb + 48;
		write(fd, &val, 1);
	}
	if (nb > 9) {
		rpg_file_put_nbr(fd, nb / 10);
		rpg_file_put_nbr(fd, nb % 10);
	}
	return (0);
}

static int rpg_player_save_fd(void)
{
	int fd = 0;

	fd = open("resources/player.json", O_WRONLY | O_CREAT);
	return (fd);
}

int rpg_player_save(player_info_t *player)
{
	int fd = 0;
	int tmp = 0;
	if (!player)
		return 84;
	fd = rpg_player_save_fd();
	write(fd, "{\n\t\"name\": \"" , my_strlen("{\n\t\"name\": \""));
	write(fd, player->name, my_strlen(player->name));
	write(fd, "\",\n\t\"x\": ", my_strlen("\",\n\t\"x\": "));
	tmp = player->x;
	rpg_file_put_nbr(fd, tmp);
	write(fd, ",\n\t\"y\": ", my_strlen(",\n\t\"y\": "));
	tmp = player->y;
	rpg_file_put_nbr(fd, tmp);
	write(fd, ",\n\t\"health\": ", my_strlen(",\n\t\"health\": "));
	rpg_file_put_nbr(fd, player->health);
	write(fd, ",\n\t\"max_health\": ",
	      my_strlen(",\n\t\"max_health\": "));
	rpg_file_put_nbr(fd, player->max_health);
	write(fd, ",\n\t\"mana\": ", my_strlen(",\n\t\"mana\": "));
	rpg_file_put_nbr(fd, player->mana);
	write(fd, ",\n\t\"skill_point\": ",
	      my_strlen(",\n\t\"skill_point\": "));
	rpg_file_put_nbr(fd, player->skill_point);
	write(fd, ",\n\t\"inv_size\": ",
	      my_strlen(",\n\t\"inv_size\": "));
	//rpg_file_put_nbr(player->inv_size);
	rpg_file_put_nbr(fd, 1);
	write(fd, ",\n\t\"direction\": ",
	      my_strlen(",\n\t\"direction\": "));
	rpg_file_put_nbr(fd, player->direction);
	write(fd, ",\n\t\"zone\": ", my_strlen(",\n\t\"zone\": "));
	rpg_file_put_nbr(fd, player->zone);
	write(fd, "\n}" , my_strlen("\n}"));
	close(fd);
	return (0);
}

int rpg_player_create_json(void)
{
	int fd = open("resources/player.json", O_WRONLY | O_CREAT);

	write(fd, "{\n\t\"name\": \"" , my_strlen("{\n\t\"name\": \""));
	write(fd, "new", my_strlen("new"));
	write(fd, "\",\n\t\"x\": ", my_strlen("\",\n\t\"x\": "));
	rpg_file_put_nbr(fd, 20 * 32);
	write(fd, ",\n\t\"y\": ", my_strlen(",\n\t\"y\": "));
	rpg_file_put_nbr(fd, 95 * 32);
	write(fd, ",\n\t\"health\": ", my_strlen(",\n\t\"health\": "));
	rpg_file_put_nbr(fd, 100);
	write(fd, ",\n\t\"max_health\": ",
	      my_strlen(",\n\t\"max_health\": "));
	rpg_file_put_nbr(fd, 100);
	write(fd, ",\n\t\"mana\": ", my_strlen(",\n\t\"mana\": "));
	rpg_file_put_nbr(fd, 100);
	write(fd, ",\n\t\"skill_point\": ",
	      my_strlen(",\n\t\"skill_point\": "));
	rpg_file_put_nbr(fd, 0);
	write(fd, ",\n\t\"inv_size\": ",
	      my_strlen(",\n\t\"inv_size\": "));
	rpg_file_put_nbr(fd, 3);
	write(fd, ",\n\t\"direction\": ",
	      my_strlen(",\n\t\"direction\": "));
	rpg_file_put_nbr(fd, 0);
	write(fd, ",\n\t\"zone\": ", my_strlen(",\n\t\"zone\": "));
	rpg_file_put_nbr(fd, 1);
	write(fd, "\n}" , my_strlen("\n}"));
	close(fd);
	my_putstr("Ok");
	return (0);
}
