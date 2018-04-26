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

static int rpg_json_items_data_list(items_data_first_t *first, const nx_json *items)
{
	int *data = malloc(sizeof(int) * 3);
	char **string = malloc(sizeof(char*) * 3);

	if (!data) {
		my_putstr("Error: malloc not found\n");
		return (-1);
	}
	data[0] = nx_json_get(items, "id")->int_value;
	data[1] = nx_json_get(items, "type")->int_value;
	string[0] = (char*)&nx_json_get(items, "name")->text_value;
	string[1] = (char*)&nx_json_get(items, "texture")->text_value;
	rpg_items_data_inject(first, string, data,
	nx_json_get(items, "stats")->dbl_value);
	free(data);
	return (0);
}

static char *rpg_items_data_load(char *filepath)
{
	char tmp_b[2];
	char *board = NULL;
	int lenght = 0;
	int fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		my_putstr("Error: items.json not found\n");
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

int rpg_json_init_items_data(items_data_first_t *first)
{
	char *read_file = rpg_items_data_load("./resources/items.json");
	const nx_json* json;
	const nx_json* items;
	const nx_json* tmp;
	if (!read_file) {
		my_putstr("Error: File not found\n");
		return (-1);
	}
	json = nx_json_parse(read_file, 0);
	if (json) {
		items = nx_json_get(json, "items");
		for (int i = 0; i < items->length; i++) {
			tmp = nx_json_item(items, i);
			rpg_json_items_data_list(first, tmp);
		}
	}
	return (0);
}
