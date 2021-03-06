/*
** EPITECH PROJECT, 2018
** rpg_inject_object_list.c
** File description:
** MODIFIER
*/

#include <stdio.h>
#include "my_rpg.h"

int rpg_inject_object_list(object_first_t *info, const nx_json *data, int pos)
{
	object_info_t *new = malloc(sizeof(object_info_t) * 2);
	const nx_json *item = nx_json_item(data, pos);
	const char *tmp = nx_json_get(item, "name")->text_value;
	if (!new || !info || !data) {
		my_putstr("Error: malloc new struct\n");
		return (-1);
	}
	new->name = my_strdup(tmp);
	new->x = nx_json_get(item, "x")->int_value;
	new->y = nx_json_get(item, "y")->int_value;
	new->z = nx_json_get(item, "z")->int_value;
	new->cooldown = 0;
	new->collider = nx_json_get(item, "collider")->int_value;
	new->type = nx_json_get(item, "type")->int_value;
	new->visible = nx_json_get(item, "visible")->int_value;
	new->texture = sfTexture_createFromFile(nx_json_get(item,
	"texture")->text_value, NULL);
	new->next = info->first;
	info->first = new;
	return 0;
}

static int rpg_inject_object_grass_list_m(object_first_t *info, int x, int y)
{
	object_info_t *new = malloc(sizeof(object_info_t));

	if (!info || !new || !info->first) {
		my_putstr("Error: value gift is null\n");
		return (-1);
	}
	new->name = NULL;
	new->x = x;
	new->y = y;
	new->z = -1;
	new->collider = 0;
	new->type = 0;
	new->visible = 0;
	new->texture = sfTexture_createFromFile(
	"./resources/sprites/map/herb.png", NULL);
	new->sprite = NULL;
	new->next = info->first;
	info->first = new;
	return (0);
}

static int rpg_inject_object_grass_x(object_first_t *info, int y)
{
	for (int j = 0; j < 100; j += 1) {
		if (rpg_inject_object_grass_list_m(info, j, y) == -1)
			return (-1);
	}
	return (0);
}

int rpg_inject_object_grass_list(object_first_t *info)
{
	for (int i = 0; i < 100; i += 1) {
		if (rpg_inject_object_grass_x(info, i) == -1)
			return (-1);
	}
	return (0);
}
