/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Function that prints a string
*/

#include "lib.h"

int my_putstr(char *str)
{
	int i = 0;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i = i + 1;
	}
	return (0);
}
