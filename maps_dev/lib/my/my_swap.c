/*
** EPITECH PROJECT, 2018
** MY_SWAP.C
** File description:
** 	This function is used for swap int
*/

#include "my.h"

void my_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
