/*
** EPITECH PROJECT, 2018
** MY_STRCAT.C
** File description:
** 	This function fusion two string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int offset = 0;
	int lenght = 0;

	while (dest[offset] != '\0')
		offset++;
	while (src[lenght] != '\0') {
		dest[offset + lenght] = src[lenght];
		lenght++;
	}
	return (dest);
}

char *my_strcat_malloc(char *dest, char const *src)
{
	int offset = 0;
	int lenght = 0;
	char *str = malloc(sizeof(char) * 100);

	while (dest[offset] != '\0') {
		str[offset] = dest[offset];
		offset++;
	}
	while (src[lenght] != '\0') {
		str[offset + lenght] = src[lenght];
		lenght++;
	}
	return (str);
}
