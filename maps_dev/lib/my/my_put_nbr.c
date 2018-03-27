/*
** EPITECH PROJECT, 2018
** MY_PUT_NBR.C
** File description:
** 	This function display one int
*/

#include "my.h"

void my_put_nbr(int nb)
{
	int start = 0;
	int end = 0;

	if (nb < 0) {
		my_putchar('-');
		my_put_nbr(-nb);
	} else {
		end = nb % 10;
		start = nb / 10;
		if (start != 0)
			my_put_nbr(start);
		my_putchar(end + '0');
	}
}
