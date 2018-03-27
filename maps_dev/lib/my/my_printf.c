/*
** EPITECH PROJECT, 2017
** MY_PRINTF.C
** File description:
** 	This function has use for main printf
*/

#include <stdarg.h>
#include "my.h"

int my_printf_displayer_str (int nb, char str, char str_bis, char str_more)
{
	if (str == '%' && str_bis == 'o' || str == '%' && str_bis == 's' ||
	    str == '%' && str_bis == 'S' || str == '%' && str_bis == 'X' ||
	    str == '%' && str_bis == 'x' || str == '%' && str_bis == 'p' ||
	    str == '%' && str_bis == 'c' || str == '%' && str_bis == 'd' ||
	    str == '%' && str_bis == 'i' || str == '%' && str_bis == 'm' ||
	    str == '%' && str_bis == 'b' || str == '%' && str_bis == '%')
		return nb + 1;
	else
		my_putchar(str);
	return nb;
}

void my_printf (char *format, ...)
{
	va_list list;

	va_start (list, format);
	for (int i = 0; format [i] != '\0'; i++) {
		select_printf (format [i], format [i+1], list);
		select_printf_bis (format [i], format [i+1], list);
		select_printf_end (format [i], format [i+1], list);
		i = my_printf_displayer_str (i, format [i], format [i+1]
					     , format [i+2]);
	} va_end (list);
}
