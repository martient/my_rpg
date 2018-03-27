/*
** EPITECH PROJECT, 2018
** MY_STR_ISNUM.C
** File description:
** 	This file check status number
*/

#include "my.h"

int my_str_isnum(char const *str)
{
	int index = 0;
	int checker = 0;

	if (str[0] == '\0')
		return 1;
	while (str[index] != '\0') {
		if (str[index] < 48 || str[index] > 57)
			return 0;
		else
			checker = 1;
		index++;
	}
	return checker;
}
