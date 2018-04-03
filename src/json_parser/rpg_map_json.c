/*
** EPITECH PROJECT, 2018
** rpg_map_json.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_json_map_init(object_first_t *info)
{
	char *read_file = rpg_map_load("./map/obj.json");
	if (!read_file) {
		my_putstr("lol\n");
		exit(84);
	}
	my_putstr("lolmdsr\n");
	nx_json* json = nx_json_parse(read_file, 0);
	my_putstr("lolmdr\n");
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
