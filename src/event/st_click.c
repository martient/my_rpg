/*
** EPITECH PROJECT, 2018
** st_click.c
** File description:
** skill tree click function
*/

#include "my_rpg.h"

static int check_click(sfVector2f position, sfVector2f scale,
sfVector2f pos)
{
	if (pos.x < position.x + 16 * scale.x &&
	pos.x > position.x - 16 * scale.x &&
	pos.y < position.y + 16 * scale.y &&
	pos.y > position.y - 16 * scale.y)
		return (1);
	return (0);
}

int st_mouse_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f pos;
	sfVector2f scale =
	{1.5 * (game->width / 800), 1.5 * (game->height / 600)};
	sfVector2f position =
	{(game->player->x) - (game->width  / 4) -
	(32 * scale.x / 2) + (32 * scale.x),
	0};
	skills_func_t skill_func[4] = {upgrade_power, upgrade_inventory,
	upgrade_life, upgrade_knight_attacks};

	pos = screen_to_world_click(game, event);
	for (int i = 1; i < 5; i++) {
		position.y = (game->player->y) - (game->height / 4) -
		(32 * scale.y / 2) + (32 * scale.y * (i * 2));
		if (check_click(position, scale, pos))
			skill_func[i - 1](game);
	}
	return (0);
}