/*
** EPITECH PROJECT, 2018
** MY_STRNCAT.C
** File description:
** 	This function fusion n char to one string
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
	int offset = 0;
	int lenght = 0;

	while (dest[offset] != '\0')
		offset++;
	while (lenght < nb) {
		dest[offset + lenght] = src[lenght];
		lenght++;
	}
	return (dest);
}

char *my_alloc_gtn(char *dest, char const *src, int lenght, int *pos)
{
	char *tmp;
	int i = 0;
	int j = *pos;

	if (dest == 0)
		dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	else {
		i = my_strlen(dest);
		tmp = malloc(sizeof(char) * (i + j));
		for (int x = 0; dest[x] != '\0'; i++)
			tmp[i] = dest[i];
	}
	for (; src[j] != '\n' && j < lenght; i++, j++)
		tmp[i] = src[j];
	tmp[i] = '\0';
	*pos = j;
	return (tmp);
}
