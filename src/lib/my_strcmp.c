/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Function that compare two strings
*/

#include "my_rpg.h"

int my_strcmp(char *str, char *str2)
{
	int i = 0;

	if (my_strlen(str) != my_strlen(str2))
		return (-1);
	while (str[i] != '\0') {
		if (str[i] < str2[i])
			return (-1);
		if (str[i] > str2[i])
			return (1);
		i = i + 1;
	}
	return (0);
}