/*
** EPITECH PROJECT, 2018
** rpg_save_inventory.c
** File description:
** Epitech project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "save.h"

static int rpg_inventory_save_items(inventory_t *items, int fd)
{
	write(fd, INVENTORY_SAVE_1, my_strlen(INVENTORY_SAVE_1));
	write(fd, items->name, my_strlen(items->name));
	write(fd, INVENTORY_SAVE_2, my_strlen(INVENTORY_SAVE_2));
	rpg_file_put_nbr(fd, items->quantity);
	write(fd, INVENTORY_SAVE_3, my_strlen(INVENTORY_SAVE_3));
	return (0);
}

int rpg_inventory_save(inventory_list_t *first)
{
	inventory_t *move = NULL;
	int fd = 0;

	if (!first) {
		my_putstr("Error: with the value gift (inv)\n");
		return (84);
	}
	move = first->first;
	fd = open(INVENTORY_SAVE_FILE, O_WRONLY | O_CREAT, 0666);
	write(fd, INVENTORY_SAVE_START, my_strlen(INVENTORY_SAVE_START));
	while (move != NULL) {
		rpg_inventory_save_items(move, fd);
		move = move->next;
	}
	write(fd, INVENTORY_SAVE_END, my_strlen(INVENTORY_SAVE_END));
	close(fd);
	return (0);
}
