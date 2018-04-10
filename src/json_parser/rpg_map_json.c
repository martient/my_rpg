/*
** EPITECH PROJECT, 2018
** rpg_map_json.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_json_map_init(object_first_t *info)
{
	char *read_file = rpg_map_load("./resources/obj.json");
	const nx_json* json;
	const nx_json* map;
	if (!read_file) {
		my_putstr("Error: File not found\n");
		return (-1);
	}
	json = nx_json_parse(read_file, 0);

	if (json) {
		//tele = nx_json_get(json, "teleportation");
		map = nx_json_get(json, "map");
		for (int i = 0; i < map->length; i++) {
			rpg_inject_object_list(info, map, i);
		}
	}
	return (0);
}
