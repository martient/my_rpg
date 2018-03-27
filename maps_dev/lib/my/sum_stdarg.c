/*
** EPITECH PROJECT, 2017
** SUM_STDARG.C
** File description:
** 	This function has use for display if i=1 result of addition or i=1
*/

#include <stdarg.h>
#include "my.h"

int sum_stdarg (int i, int nb, ...)
{
	int result = 0;
	va_list list;

	if (i == 0) {
		va_start (list, nb);
		for (int index = 0; index < nb; index++)
			result += va_arg(list, int);
	} if (i == 1) {
		va_start (list, nb);
		for (int index = 0; index < nb; index++)
			result += my_strlen(va_arg(list, char*));
	}
	va_end (list);
	return result;
}
