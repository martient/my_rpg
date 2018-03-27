/*
** EPITECH PROJECT, 2018
** MY_STRUPCASE.C
** File description:
** 	This function is used for upcase char
*/

#include "my.h"

char *my_strupcase(char *str)
{
	int indexer = 0;

	while (str [indexer] != '\0') {
		if (str [indexer] >= 'a' && str [indexer] <= 'z')
			str[indexer] = str[indexer] - 32;
		indexer++;
	}
	return str;
}
