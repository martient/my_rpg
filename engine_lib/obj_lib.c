/*
** EPITECH PROJECT, 2018
** obj_lib.c
** File description:
** engine lib for objects
*/

#include "my_rpg.h"

object_info_t *engine_object_get_first(object_info_t *obj)
{
	object_info_t *head = obj;

	while (obj->previous)
	{
		obj = obj->previous;
	}
	return (obj);
}