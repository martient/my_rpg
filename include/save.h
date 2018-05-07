/*
** EPITECH PROJECT, 2018
** save.h
** File description:
** Header save.h
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "inventory.h"
#include "player.h"

#define INVENTORY_SAVE_FILE "./resources/player_inventory.json"
#define INVENTORY_SAVE_START "{\n\t\"items\": [\n"
#define INVENTORY_SAVE_END "\t],\n}"
#define INVENTORY_SAVE_1 "\t\t{ \"name\": \""
#define INVENTORY_SAVE_2 "\", \"amount\": "
#define INVENTORY_SAVE_3 "},\n"

#define PLAYER_SAVE_FILE "resources/player.json"
#define PLAYER_SAVE_NAME "{\n\t\"name\": \""
#define PLAYER_SAVE_X "\",\n\t\"x\": "
#define PLAYER_SAVE_Y ",\n\t\"y\": "
#define PLAYER_SAVE_HEALTH ",\n\t\"health\": "
#define PLAYER_SAVE_MAX_HEALTH ",\n\t\"max_health\": "
#define PLAYER_SAVE_MANA ",\n\t\"mana\": "
#define PLAYER_SAVE_SKILL_POINT ",\n\t\"skill_point\": "
#define PLAYER_SAVE_INV_SIZE ",\n\t\"inv_size\": "
#define PLAYER_SAVE_DIR ",\n\t\"direction\": "
#define PLAYER_SAVE_ZONE ",\n\t\"zone\": "
#define PLAYER_SAVE_END "\n}"

int rpg_inventory_save(inventory_list_t *first);
int rpg_player_save(player_info_t *player);
#endif
