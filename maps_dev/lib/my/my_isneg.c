/*
** EPITECH PROJECT, 2017
** MY_ISNEG
** File description:
**	Displays N or P according to given number.
*/

#include "my.h"

int my_isneg(int n)
{
	if (n < 0)
		my_putchar (78);
	else
		my_putchar (80);
	return (0);
}
