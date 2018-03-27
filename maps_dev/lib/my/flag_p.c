/*
** EPITECH PROJECT, 2017
** FLAG_P.C
** File description:
** 	This function has use for display pointer any type
*/

#include "my.h"

void printf_flag_p (unsigned int value)
{
	my_putchar ('0');
	my_putchar ('x');
	my_put_nbr_base_min (value, "0123456789abcdef");
}
