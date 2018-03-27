/*
** EPITECH PROJECT, 2018
** MY_STRCAPITALIZE.C
** File description:
** 	This file switch upercase first letter
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
	int indexer = 0;
	int i = 0;

	while (str[indexer] != '\0') {
		if (str[indexer] >= 'A' && str[indexer] <= 'Z')
			str[indexer] = str[indexer] + 32;
		indexer++;
	}
	while (str[i] != '\0') {
		if (str[i] == ' ' && (str[i+1] >= 'a' && str[i+1] <= 'z'))
			str[i+1] = str[i+1] - 32;
		if (i == 0 && (str[0] >= 'a' && str[0] <= 'z'))
			str[0] = str[0] - 32;
		i++;
	}
	return str;
}
