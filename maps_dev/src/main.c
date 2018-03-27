/*
** EPITECH PROJECT, 2018
** @Filename: main.c
** File description:
**	MODIFIER
*/

int main(int argc, char const *argv[]) {
	while (1) {

	}
	return 0;
}

void rpg_gen_map_read(/* arguments */) {
	/* code */
}

void rpg_gen_map_display(char **tetrimino)
{
	for (int i = 1; tetrimino[i] != NULL; i++) {
		for (int j = 0; j < my_strlen(tetrimino[i]); j++) {
			my_putchar(tetrimino[i][j]);
		}
	}
	my_putchar('\n');
}
