/*
** EPITECH PROJECT, 2018
** global.h
** File description:
** Header file for the definition of the global structure
*/

#ifndef GLOBAL_H_
	#define GLOBAL_H_

#include <SFML/Graphics.h>
#include "inventory.h"
#include "items_data.h"

typedef struct game_global_t {
	sfRenderWindow *window;
	sfClock *clock;
	int height;
	int width;
	int screen_id;
	int frame_rate;
	int state;
	double zoom;
	int inventory_show;
	int skill_tree_show;
	sfFont *font;
	struct player_info_t *player;
	inventory_list_t *invent;
	struct map_info_t *info_map;
	struct skills_t *tree;
	struct spawn_first_t *mob_spawn;
	struct mob_first_t *mob_deploy;
	struct mob_data_first_t *mob_data;
	struct items_data_first_t *items_data;
	struct sound_info_t *sound;
	items_data_t *invent_item;
} game_global_t;

game_global_t *__init__(void);
int rpg_json_init_inventory_data(game_global_t *global);

#endif /* !GLOBAL_H_ */
