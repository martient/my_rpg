/*
** EPITECH PROJECT, 2018
** MY_STRNCPY.C
** File description:
** 	This file content function to cpy n char
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int indexer = 0;

	while (indexer < n) {
		if (src[indexer] == '\0') {
			dest[indexer] = '\0';
			return;
		}
		else {
			dest[indexer] = src[indexer];
			indexer++;
		}
	}
	return (dest);
}

char *my_strncpy_last(char *dest, char const *src, int last, int n)
{
	int i = 0;

	while (i+last < n) {
		if (src[i+last] == '\0') {
			dest[i] = '\0';
			return;
		}
		else {
			dest[i] = src[i+last];
			i++;
		}
	}
	return (dest);
}
