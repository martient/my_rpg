/*
** EPITECH PROJECT, 2018
** MY_STRNCMP.C
** File description:
** 	This file compare n char
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (i < n  && (s1[i] != '\0' && s2[i] != '\0')) {
		if (s1[n] < s2[n])
			return -1;
		else if (s1[n] > s2[n])
			return 1;
		else
			i++;
	}
	return 0;
}
