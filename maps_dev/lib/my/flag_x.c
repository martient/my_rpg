/*
** EPITECH PROJECT, 2017
** FLAG_X.C
** File description:
** 	Function flag x for printf (hexadécimal)
*/

#include "my.h"

void printf_flag_x (unsigned int value)
{
	my_put_nbr_base_min (value, "0123456789abcdef");
}

void printf_flag_X (unsigned int value)
{
	my_put_nbr_base_maj (value, "0123456789ABCDEF");
}
