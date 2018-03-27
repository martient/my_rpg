/*
** EPITECH PROJECT, 2018
** MY_STR_ISALPHA.C
** File description:
** 	This file check is letter
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
	int index = 0;
	int checker = 0;

	if (str[0] == '\0')
		return 1;
	while (str[index] != '\0') {
		if (str[index] >= 'a' && str[index] <= 'z')
			checker = 1;
		else if (str[index] >= 'A' && str[index] <= 'Z')
			checker = 1;
		else
			return 0;
		index++;
	}
	return checker;
}
