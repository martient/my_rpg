/*
** EPITECH PROJECT, 2018
** MY_PUTCHAR.C
** File description:
** 	This function display one char
*/

#include "my.h"

void write(int, char *add, int);

void my_putchar(char c)
{
	write(1, &c, 1);
}
