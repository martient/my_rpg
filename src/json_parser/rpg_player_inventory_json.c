/*
** EPITECH PROJECT, 2018
** rpg_player_inventory_json.c
** File description:
** Epitech project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"

static int rpg_json_player_inv_list(game_global_t *global,
const nx_json *mob)
{
	if (!mob && !global) {
		my_putstr("Error: malloc not found\n");
		return (-1);
	}
	for (int i = 0; i < nx_json_get(mob, "amount")->int_value; i++)
		if (inventory_new_obj(global,
		my_strdup(nx_json_get(mob,"name")->text_value)) == 1)
			return (0);
	return (0);
}

static char *rpg_mob_inventory_load(char *filepath)
{
	char tmp_b[2];
	char *board = NULL;
	int lenght = 0;
	int fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		my_putstr("Error: player_inventory.json not found\n");
		return (NULL);
	}
	while (read(fd, tmp_b, 1))
		lenght += 1;
	close(fd);
	board = malloc(sizeof(char) * lenght + 1);
	fd = open(filepath, O_RDONLY);
	read(fd, board, lenght);
	board[lenght] = '\0';
	close(fd);
	return board;
}

int rpg_json_init_inventory_data(game_global_t *global)
{
	char *read_file = rpg_mob_inventory_load(
	"./resources/player_inventory.json");
	const nx_json* json;
	const nx_json* mob;
	const nx_json* tmp;

	if (!read_file) {
		my_putstr("Error: File not found\n");
		return (-1);
	}
	json = nx_json_parse(read_file, 0);
	if (json) {
		mob = nx_json_get(json, "items");
		for (int i = 0; i < mob->length; i++) {
			tmp = nx_json_item(mob, i);
			rpg_json_player_inv_list(global, tmp);
		}
	}
	free(read_file);
	return (0);
}
