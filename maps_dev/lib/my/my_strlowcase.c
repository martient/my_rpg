/*
** EPITECH PROJECT, 2018
** MY_STRLOWCASE.C
** File description:
** 	This file switch to low case
*/

#include "my.h"

char *my_strlowcase(char *str)
{
	int index = 0;

	while (str[index] != '\0') {
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] + 32;
		index++;
	}
	return str;
}
