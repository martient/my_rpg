/*
** EPITECH PROJECT, 2018
** MY_STRLEN.C
** File description:
** 	This function count number char
*/

#include "my.h"

int my_strlen(char const *str)
{
	int lenght = 0;

	while (str[lenght] != '\0') {
		lenght++;
	}
	return lenght;
}

int my_strlen_double(char const **str)
{
	int lenght = 0;

	while (str [0][lenght] != '\0') {
		lenght++;
	}
	return lenght;
}
