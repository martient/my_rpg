/*
** EPITECH PROJECT, 2017
** DISP_STDARG.C
** File description:
** 	This function has use for display string in increasing order and \n
*/

#include <stdarg.h>
#include "my.h"

void disp_stdarg (char *s, ...)
{
	va_list list;

	va_start (list, *s);
	for (int i = 0; i < *s; i++) {
		if (s [i] == 'c') {
			my_putchar ((char)va_arg(list, int));
			my_putchar ('\n');
		}
		if (s [i] == 's') {
			my_putstr (va_arg(list, char*));
		} else if (s [i] == 'i') {
			my_put_nbr (va_arg(list, int));
			my_putchar ('\n');
		}
	}
	va_end(list);
}
