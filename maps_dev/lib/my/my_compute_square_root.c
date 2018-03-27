/*
** EPITECH PROJECT, 2018
** MY_COMPUTE_SQUARE_ROOT.C
** File description:
** 	This file is mind
*/

#include "my.h"

int my_compute_square_root(int nb)
{
	int value = 0;
	int square_root = 0;
	int index = 0;

	for (index = 1; index < (nb / 2); index++) {
		value = index * index;
		if (value == nb) {
			square_root = index;
			return square_root;
		}
	}
	return 0;
}
