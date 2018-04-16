/*
** EPITECH PROJECT, 2018
** rpg_json_reader.c
** File description:
** MODIFIER
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"

char *rpg_map_load(char *filepath)
{
	char tmp_b[2];
	char *board = NULL;
	int lenght = 0;
	int fd = 0;

	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		rpg_player_create_json();
	} else {
		while (read(fd, tmp_b, 1))
		lenght += 1;
	}
	close(fd);
	board = malloc(sizeof(char) * lenght + 1);
	fd = open(filepath, O_RDONLY);
	read(fd, board, lenght);
	board[lenght] = '\0';
	close(fd);
	return board;
}
