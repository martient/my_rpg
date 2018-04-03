/*
** EPITECH PROJECT, 2018
** MY_PUTCHAR.C
** File description:
** 	This function display one char
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
