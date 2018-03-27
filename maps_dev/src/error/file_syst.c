/*
** EPITECH PROJECT, 2018
** FILE_SYST.C
** File description:
** 	This file content error handling of tetris project file
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"
#include "file_syst.h"

int rpg_gen_map_open_repo_tetriminos(game_info_t *info)
{
	DIR *filepath = opendir("./map");
	struct dirent* file_read;
	int value = 0;
	if (!info) {
		my_putstr("Error: Element gift is NULL\n");
		exit(84);
	}
	while ((file_read = readdir(filepath)) != 0) {
		if (file_read->d_name[0] != '.') {
			value = tetris_file_good_name(file_read->d_name);
			(value == 1) ? tetris_open_repo_file(info,
				 file_read->d_name) : NULL;
		}
		value = 0;
	}
	closedir(filepath);
	return 0;

}

int rpg_gen_map_file_good_name(char *str)
{
	int lenght = 0;

	if (str == NULL) {
		return -1;
	}
	lenght = my_strlen(str) - 1;
	if (lenght < 7) {
		return -1;
	} else if (str[lenght] == 't' && str[lenght - 1] == 'x' &&
		str[lenght - 2] == 'e' && str[lenght - 3] == 'g' &&
		str[lenght - 4] == 'p' && str[lenght - 5] == 'r' &&
		str[lenght - 6] == '.') {
		return 1;
	}
	return 0;
}

void rpg_gen_map_boucle_check_letter_file(game_tetrimino_t *info)
{
	for (int i = 1; info->tetrimino[i] != NULL; i++) {
		if (tetris_check_letter_in_file(info->tetrimino[i]) == 1) {
			info->ok = 1;
		}
	}
}

int tetris_check_letter_in_file(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i] != NULL; i++) {
		if (buffer[i] != ' ' && buffer[i] != '\n' &&
		 buffer[i] != '*' && buffer[i] != '\0') {
			return 1;
		}
	}
	return 0;
}

int tetris_check_letter_in_str(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i] != NULL; i++) {
		if (buffer[i] < 48 && buffer[i] > '9' && buffer[i] != '\n' &&
		 buffer[i] != ' ') {
			return 1;
		}
	}
	return 0;
}
