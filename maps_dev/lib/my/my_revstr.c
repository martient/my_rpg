/*
** EPITECH PROJECT, 2018
** MY_REVSTR.C
** File description:
** 	This file is mind
*/

#include "my.h"

char *my_revstr(char *str)
{
	int i = 0;
	int j = 0;
	char tmp = 0;

	while (str[i] != '\0')
		i++;
	i--;
	while (i > j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i--;
		j++;
	}
	return (str);
}
