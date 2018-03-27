/*
** EPITECH PROJECT, 2018
** MY_SORT_INT_ARRAY.C
** File description:
** 	This file is mind
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j <= size-1; j++) {
			my_sort_int_array_switch(i, j, array);
		}
	}
}

void my_sort_int_array_switch(int i, int j, int *array)
{
	int tmp = 0;

	if (array[i] > array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
