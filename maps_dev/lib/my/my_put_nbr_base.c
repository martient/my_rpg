/*
** EPITECH PROJECT, 2017
** MY_PUT_NBR_BASE
** File description:
** 	This function has use for manage base
*/

#include "my.h"

int my_put_nbr_base_min (unsigned int number, char *str)
{
	int lenght = my_strlen (str);

	if (number < 10) {
		my_putchar (number + '0');
	} else if (lenght <= number) {
		my_put_nbr_base_min (lenght / number, str);
		my_put_nbr_base_min (lenght % number, str);
	} else
		my_putchar(number + 87);
}

int my_put_nbr_base_maj (unsigned int number, char *str)
{
	int lenght = my_strlen (str);

	if (number < 10)
		my_putchar (number + '0');
	else if (lenght <= number) {
		my_put_nbr_base_maj (lenght / number, str);
		my_put_nbr_base_maj (lenght % number, str);
	} else
		my_putchar (number + 55);
}

int my_put_nbr_base_octale (unsigned int number, char *str)
{
	int lenght = my_strlen (str);

	if (number < 10)
		my_putchar (number + '0');
	else if (lenght <= number) {
		my_put_nbr_base_maj (lenght / number, str);
		my_put_nbr_base_maj (lenght % number, str);
	} else
		my_putchar (number + 87);
}

int my_put_nbr_base_binaire (unsigned int number, char *str)
{
	int lenght = my_strlen (str);

	if (number < 10)
		my_putchar (number + '0');
	else if (lenght <= number) {
		my_put_nbr_base_maj (lenght / number, str);
		my_put_nbr_base_maj (lenght % number, str);
	} else
		my_putchar (number + 87);
}
