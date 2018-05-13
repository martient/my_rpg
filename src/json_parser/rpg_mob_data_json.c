/*
** EPITECH PROJECT, 2018
** rpg_mob_json.c
** File description:
** Epitech project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"

static int rpg_json_mob_data_list(mob_data_first_t *f, const nx_json *m)
{
	float *data = malloc(sizeof(float) * 8);

	if (!data) {
		my_putstr("Error: malloc not found\n");
		return (-1);
	}
	data[0] = nx_json_get(m, "attack_base")->dbl_value;
	data[1] = nx_json_get(m, "attack_grow")->dbl_value;
	data[2] = nx_json_get(m, "healt_base")->dbl_value;
	data[3] = nx_json_get(m, "healt_grow")->dbl_value;
	data[4] = nx_json_get(m, "armor_base")->dbl_value;
	data[5] = nx_json_get(m, "armor_grow")->dbl_value;
	data[6] = nx_json_get(m, "speed")->dbl_value;
	data[7] = -1;
	rpg_mob_data_inject(f, data, nx_json_get(m, "id")->int_value,
	my_strdup(nx_json_get(m, "name")->text_value));
	rpg_mob_data_tex_inject(f, my_strdup(
	nx_json_get(m, "texture")->text_value));
	free(data);
	return (0);
}

static char *rpg_mob_data_load(char *filepath)
{
	char tmp_b[2];
	char *board = NULL;
	int lenght = 0;
	int fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		my_putstr("Error: mobs.json not found\n");
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

int rpg_json_init_mob_data(mob_data_first_t *first)
{
	char *read_file = rpg_mob_data_load("./resources/mobs.json");
	const nx_json* json;
	const nx_json* mob;
	const nx_json* tmp;
	if (!read_file) {
		my_putstr("Error: File not found\n");
		return (-1);
	}
	json = nx_json_parse(read_file, 0);
	if (json) {
		mob = nx_json_get(json, "list_mobs");
		for (int i = 0; i < mob->length; i++) {
			tmp = nx_json_item(mob, i);
			rpg_json_mob_data_list(first, tmp);
		}
	}
	return (0);
}
