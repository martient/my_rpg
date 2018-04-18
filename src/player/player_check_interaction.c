/*
** EPITECH PROJECT, 2018
** player_check_interaction.c
** File description:
** function to popup messages on interaction
*/

#include "my_rpg.h"

int can_interact(object_info_t *map, player_info_t *player)
{
	double x = player->x;
	double y = player->y;

	if (x < -10 || x > 99 * 32 || y < 10 || y > 99 * 32)
		return 1;
	while (map) {
		if (map->type != 1) {
			map = map->next;
			continue;
		}
		if (x <= (map->x * 32) + 64 &&
		x + 39 >= (map->x * 32) - 64 &&
		y <= (map->y * 32) + 64 &&
		y >= (map->y * 32) - 64) {
			return (1);
		}
		map = map->next;
	}
	return (0);
}

void show_interact_button(game_global_t *game)
{
	char *text = "Press {E} to interact.";
	int info[3] = {game->player->x - 150, game->player->y + (game->height / 2) - 120, 32};
	sfColor color = sfWhite;

	engine_create_text(game, text, info, color);
}
void player_check_interaction(game_global_t *game)
{
	object_info_t *map = game->info_map->first->first;
	player_info_t *player = game->player;

	if (can_interact(map, player)) {
		show_interact_button(game);
	}
}