/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** Function that returns the length of a string
*/

#include "lib.h"

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
