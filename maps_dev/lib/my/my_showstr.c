/*
** EPITECH PROJECT, 2018
** MY_SHOWSTR.C
** File description:
** 	This file is mind
*/

#include "my.h"

void display_digits(char *str)
{
	int i = 0;

	if (str [i] < 16)
		my_putchar('0');
	my_putnbr_base(str[i], "0123456789");
}

int my_showstr(char const *str)
{
	int i = 0;

	while (str [i] != 0) {
		if (str [i] > 31)
			my_putchar(str[i]);
		else {
			my_putchar('\\');
			display_digits(str[i]);
		}
		i++;
	}
	return 0;
}
