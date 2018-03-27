/*
** EPITECH PROJECT, 2018
** MY_COMPUTE_POWER_REC.C
** File description:
** 	This is my file
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
	int result;

	if (p == 0)
		return 1;
	else if (result > 2147483647)
		return 0;
	else
		result = (nb * my_compute_power_rec(nb, p-1));
	return result;
}
