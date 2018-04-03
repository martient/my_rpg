/*
** EPITECH PROJECT, 2018
** rpg_inject_object_list.c
** File description:
** MODIFIER
*/

#include <stdio.h>
#include "my_rpg.h"

int rpg_inject_object_list(object_first_t *info, nx_json *data, int pos)
{
	object_info_t *new = malloc(sizeof(object_info_t) * 2);
	nx_json *item = nx_json_item(data, pos);

	if (!new || !info || !data) {
		my_putstr("Error: malloc new struct\n");
		return (-1);
	}
	new->name = nx_json_get(item, "name")->text_value;
	new->x = nx_json_get(item, "x")->int_value;
	new->y = nx_json_get(item, "y")->int_value;
	new->z = nx_json_get(item, "z")->int_value;
	new->collider = nx_json_get(item, "collider")->int_value;
	new->type = nx_json_get(item, "type")->int_value;
	new->visible = nx_json_get(item, "visible")->int_value;
	new->texture = nx_json_get(item, "texture")->text_value;
	new->sprite = nx_json_get(item, "sprite")->text_value;
	new->next = info->first;
	info->first = new;
	return 0;
}
