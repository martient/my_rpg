/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** int_to_string.c
*/

#include "lib.h"

int get_int_len(int number)
{
	int i = 0;

	while (number > 9) {
		i++;
		number /= 10;
	}
	i++;
	return (i);
}

char *get_bad_string(int number, int length)
{
	int i = 0;
	char *string = malloc(sizeof(char) * length + 1);

	while (number > 9) {
		string[i] = (number % 10) + 48;
		number /= 10;
		i++;
	}
	string[i] = number + 48;
	i++;
	string[i] = '\0';
	return (string);
}

char *reverse_string(char *string, int length)
{
	char *reversed_string = malloc(sizeof(char) * length + 1);
	int j = length-1;
	int i = 0;

	for (i = 0; i < length; i++) {
		reversed_string[i] = string[j];
		j--;
	}
	reversed_string[i] = '\0';
	return (reversed_string);
}

char *int_to_string(int number)
{
	int length = get_int_len(number);
	char *string;

	string = get_bad_string(number, length);
	string = reverse_string(string, length);
	return (string);
}
