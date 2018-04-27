/*
** EPITECH PROJECT, 2018
** rpg_save_inventory.c
** File description:
** Epitech project
*/

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

static int rpg_inventory_save_fd(void)
{
	int fd = 0;

	fd = open("./resources/player_inventory.json", O_WRONLY | O_CREAT);
	return (fd);
}

static int rpg_inventory_save_items(inventory_t *items, int fd)
{
	write(fd, "\t\t{ \"name\": \"", my_strlen("\t\t{ \"name\": \""));
	write(fd, items->name, my_strlen(items->name));
	write(fd, "\", \"amount\": ", my_strlen(", \"amount\": "));
	rpg_file_put_nbr(fd, items->quantity);
	write(fd, "},\n", my_strlen("},\n"));
	return (0);
}

int rpg_inventory_save(inventory_list_t *first)
{
	inventory_t *move = NULL;
	int fd = 0;

	if (!first) {
		my_putstr("Error: with the value gift\n");
		return (84);
	}
	move = first->first;
	fd = rpg_inventory_save_fd();
	write(fd, "{\n\t\"items\": [\n", my_strlen("{\n\t\"items\": [\n"));
	while (!move) {
		rpg_inventory_save_items(move, fd);
		move = move->next;
	}
	write(fd, "\t],\n}", my_strlen("\t],\n}"));
	return (0);
}
