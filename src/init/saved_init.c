/*
** EPITECH PROJECT, 2018
** saved_init.c
** File description:
** Function that initializa what has been saved
*/

#include "my_rpg.h"

void saved_init(player_info_t *player, const nx_json* json)
{
	player->name = "Patrick";
	player->x = nx_json_get(json, "x")->dbl_value;
	player->y = nx_json_get(json, "y")->dbl_value;
	player->zone = nx_json_get(json, "zone")->int_value;
	player->health = nx_json_get(json, "health")->int_value;
	player->max_health = nx_json_get(json, "max_health")->int_value;
	player->mana = nx_json_get(json, "mana")->int_value;
	player->skill_point = nx_json_get(json, "skill_point")->int_value;
	player->direction = nx_json_get(json, "direction")->int_value;
	player->xp = nx_json_get(json, "xp")->dbl_value;
	player->level = nx_json_get(json, "level")->int_value;
	player->current_quest_id = nx_json_get(json, "current_quest_id")->int_value;
}