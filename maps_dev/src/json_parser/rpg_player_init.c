/*
** EPITECH PROJECT, 2018
** rpg_player_init.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

player_info_t *rpg_map_parsed(, char *file_content)
{
	player_info_t *player = malloc(sizeof(player_info_t));
	const nx_json* json=nx_json_parse(file_content, 0);

	if (json) {
		player->name =  nx_json_get(json, "name")->text_value;
		player->x = nx_json_get(json, "x")->int_value;
		player->y = nx_json_get(json, "y")->int_value;
		player->zone nx_json_get(json, "zone")->int_value;
		return player;
	}
	return (NULL);
}
