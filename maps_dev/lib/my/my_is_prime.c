/*
** EPITECH PROJECT, 2018
** MY_IS_PRIME.C
** File description:
** 	This file is mind
*/

#include "my.h"

int my_is_prime(int nb)
{
	int index = 0;

	if (nb == 0 || nb == 1)
		return 0;
	for (index = 2; index < nb; index++) {
		if (nb % index == 0 && index != nb)
			return 0;
	}
	return 1;
}
