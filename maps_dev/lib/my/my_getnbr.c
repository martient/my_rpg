/*
** EPITECH PROJECT, 2018
** MY_GETNBR.C
** File description:
** 	This file content function translate str to nb
*/

#include "my.h"

int my_getnbr(char const* str)
{
	int i = 0;
	int number = 0;

	if (str[0] == '-' && str[1] != '\0')
		i = i + 1;
	while (str[i] != '\0') {
		if ((str[i] < '0' || str[i] > '9'))
			return 84;
		number = number * 10 - '0' + str[i];
		i++;
	}
	if (str[0] == '-')
		return (-1 * number);
	else
		return (number);
}
