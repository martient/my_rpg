/*
** EPITECH PROJECT, 2018
** rpg_map_json.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_json_map_init(object_first_t *info)
{
	nx_json* json=nx_json_parse(rpg_map_load("./map/obj.json"), 0);
//	const nx_json* tele;
	nx_json* map;

	if (json) {
		//tele = nx_json_get(json, "teleportation");
		map = nx_json_get(json, "map");
		for (int i = 0; i < map->length; i++) {
			rpg_inject_object_list(info, map, i);
		}
		return 0;
	}
	return (0);
}
