/*
** EPITECH PROJECT, 2017
** FLAG_S.C
** File description:
** 	This function has use for display string before \0
*/

#include "my.h"

void printf_flag_s (char *str)
{
	char tmp = 0;

	for (int i = 0; str [i] != '\0'; i++) {
		tmp = str [i];
		my_putchar(tmp);
	}
}

void printf_flag_S (char *str)
{
	str = str;
}
