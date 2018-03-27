/*
** EPITECH PROJECT, 2018
** MY_STR_ISUPPER.C
** File description:
** 	This file is mind
*/

#include "my.h"

int my_str_isupper(char const *str)
{
	int index = 0;
	int checker = 0;

	if (str[0] == '\0')
		return 1;
	while (str[index] != '\0') {
		if (str[index] >= 'A' && str[index] <= 'Z')
			checker = 1;
		else
			return 0;
		index++;
	}
	return checker;
}
