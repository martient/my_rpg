/*
** EPITECH PROJECT, 2018
** player_check_interaction.c
** File description:
** function to popup messages on interaction
*/

#include "my_rpg.h"

int interaction_type_1(object_info_t *map, double x, double y)
{
	if (x <= (map->x * 32) + 64 &&
	x + 39 >= (map->x * 32) - 32 &&
	y <= (map->y * 32) + 64 &&
	y >= (map->y * 32) - 64) {
		return (1);
	}
	return (0);
}

int interaction_type_2(object_info_t *map, double x, double y)
{
	y += 39;

	if (x <= (map->x * 32) + 32 &&
	x + 39 >= (map->x * 32) &&
	y <= (map->y * 32) + 32 &&
	y >= (map->y * 32)) {
		return (1);
	}
	return (0);
}

object_info_t *can_interact(object_info_t *map, player_info_t *player, int *type)
{
	double x = player->x;
	double y = player->y;

	while (map) {
		if (map->type == 1 && map->visible == 0 && interaction_type_1(map, x, y)) {
			*type = 1;
			return (map);
		}
		if (map->type == 2 && map->visible == 0 && interaction_type_2(map, x, y)) {
			*type = 2;
			return (map);
		}
		map = map->next;
	}
	*type = 0;
	return (NULL);
}

void show_interact_button(game_global_t *game)
{
	char *text = INTERACT;
	int info[3] = {game->player->x - 150, game->player->y + (game->height / 2) - 120, 32};
	sfColor color = sfWhite;

	engine_create_text(game, text, info, color);
}

void player_check_interaction(game_global_t *game)
{
	object_info_t *map = game->info_map->first->first;
	object_info_t *obj = NULL;
	player_info_t *player = game->player;
	int event_type;

	obj = can_interact(map, player, &event_type);
	if (obj != NULL) {
		show_interact_button(game);
		player->event->type = event_type;
		player->event->obj = obj;
	} else {
		player->event->type = 0;
	}
}