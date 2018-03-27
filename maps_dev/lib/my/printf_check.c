/*
** EPITECH PROJECT, 2017
** PRINTF_CHECK.C
** File description:
** 	This file has use for tchek flag or print the str.
*/

#include "my.h"

void select_printf_end (char str, char str_bis, va_list list)
{
	if (str == '%' && str_bis == 'S')
		printf_flag_S(va_arg(list, char*));
	if (str == '%' && str_bis == 'b')
		printf_flag_b (va_arg (list, unsigned int));
	if (str == '%' && str_bis == 'm')
		my_putstr ("Sucess");
	else if (str == '%' && str_bis == '%')
		my_putchar(str);
}

void select_printf_bis (char str, char str_bis, va_list list)
{
	if (str == '%' && str_bis == 'x')
		printf_flag_x (va_arg (list, unsigned int));
	if (str == '%' && str_bis == 'X')
		printf_flag_X (va_arg (list, unsigned int));
	if (str == '%' && str_bis == 'o')
		printf_flag_o (va_arg (list, unsigned int));
	else if (str == '%' && str_bis == 'p')
		printf_flag_p (va_arg (list, unsigned int));
}

void select_printf (char str, char str_bis, va_list list)
{
	if (str == '%' && str_bis == 'd')
		printf_flag_d (va_arg (list, int));
	if (str == '%' && str_bis == 'i')
		printf_flag_d (va_arg (list, int));
	if (str == '%' && str_bis == 's')
		printf_flag_s (va_arg (list, char*));
	else if (str == '%' && str_bis == 'c')
		printf_flag_c (va_arg (list, char));
}
