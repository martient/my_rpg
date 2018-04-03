/*
** EPITECH PROJECT, 2018
** MY_PUTSTR.C
** File description:
** 	This file content function for display str
*/

#include "my.h"

void my_putstr(char const *str)
{
	int index = 0;

	while (str[index] != '\0') {
		my_putchar(str[index]);
		index++;
	}
}

void my_putstr_n (char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	my_putchar ('\n');
}
