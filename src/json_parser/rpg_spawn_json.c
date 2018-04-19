/*
** EPITECH PROJECT, 2018
** rpg_spawn_json.c
** File description:
** Epitech project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"

static int rpg_json_spawn_list(spawn_first_t *first, const nx_json *mob)
{
	int *data = malloc(sizeof(int) * 4);

	if (!data) {
		my_putstr("Error: malloc not found\n");
		return (-1);
	}
	data[0] = nx_json_get(mob, "x")->int_value;
	data[1] = nx_json_get(mob, "y")->int_value;
	data[2] = nx_json_get(mob, "type")->int_value;
	data[3] = nx_json_get(mob, "rate")->int_value;
	data[4] = -1;
	rpg_spawn_inject(first, data);
	free(data);
	return (0);
}

static char *rpg_spawn_load(char *filepath)
{
	char tmp_b[2];
	char *board = NULL;
	int lenght = 0;
	int fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		my_putstr("Error: mob_spawn.json not found\n");
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

int rpg_json_init_spawn(spawn_first_t *first)
{
	char *read_file = rpg_spawn_load("./resources/mob_spawn.json");
	const nx_json* json;
	const nx_json* mob;
	const nx_json* tmp;
	if (!read_file) {
		my_putstr("Error: File not found\n");
		return (-1);
	}
	json = nx_json_parse(read_file, 0);
	if (json) {
		mob = nx_json_get(json, "list_spawn");
		for (int i = 0; i < mob->length; i++) {
			tmp = nx_json_item(mob, i);
			rpg_json_spawn_list(first, tmp);
		}
	}
	return (0);
}
