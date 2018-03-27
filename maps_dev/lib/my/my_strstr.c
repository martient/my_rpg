/*
** EPITECH PROJECT, 2018
** MY_STRSTR.C
** File description:
** 	This file content function to fond str
*/

#include "my.h"

int check_occurence(char const *str, char const *to_find, int index)
{
	int j = 0;
	int occurence = 0;

	while (to_find[j] != '\0') {
		if (to_find[j] == str[index])
			occurence = 1;
		else
			return 0;
		j++;
		index++;
	}
	return occurence;
}

char *my_strstr(char const*str, char const *to_find)
{
	int indexer = 0;
	int found_it = 0;

	while (str[indexer] != '\0') {
		if (str[indexer] == to_find[0] && !found_it)
			found_it = check_occurence(str, to_find, indexer);
		indexer++;
	}

	if (found_it)
		return str[indexer];
	else
		return '\0';
}
