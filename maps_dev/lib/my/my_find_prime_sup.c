/*
** EPITECH PROJECT, 2018
** MY_FIND_PRIME_SUP.C
** File description:
** 	This file is my
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
	if (nb > 2 && nb %2 == 0)
		nb += 1;
	while (!my_is_prime(nb))
		nb += 2;
	return nb;
}
