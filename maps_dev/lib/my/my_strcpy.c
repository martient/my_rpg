/*
** EPITECH PROJECT, 2018
** MY_STRCPY.C
** File description:
** 	This file copy in another string one
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int index = 0;

	while (src[index] != '\0') {
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
