/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** mouse_click.c
*/

#include "my_rpg.h"

sfVector2f screen_to_world(game_global_t *game, sfMouseMoveEvent event)
{
	sfVector2f world_positions;

	world_positions.x = game->player->x - game->width / 2;
	world_positions.y = game->player->y - game->height / 2;
	world_positions.x += event.x;
	world_positions.y += event.y;
	return (world_positions);
}
sfVector2f screen_to_world_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f world_positions;

	world_positions.x = game->player->x - game->width / 2;
	world_positions.y = game->player->y - game->height / 2;
	world_positions.x += event.x;
	world_positions.y += event.y;
	return (world_positions);
}

int mouse_hover(game_global_t *game, sfMouseMoveEvent event)
{
	inventory_t *inventory = game->invent->first;
	items_data_t *invent_item;
	sfVector2f pos;

	game->invent_item = NULL;
	pos = screen_to_world(game, event);
	while (inventory->name != NULL) {
		invent_item = inventory_get_items(game->items_data, inventory->name);
		if (invent_item == NULL)
			return (1);
		if (pos.x < invent_item->x + 16 &&
		pos.x > invent_item->x - 16 &&
		pos.y < invent_item->y + 16 &&
		pos.y > invent_item->y - 16)
			game->invent_item = invent_item;
		inventory = inventory->next;
		if (inventory == NULL)
			break;
	}
	return (0);
}

int which_click(game_global_t *game, sfMouseButtonEvent event, items_data_t *item)
{
	if (event.button == sfMouseRight) {
		inventory_del_obj(game->invent, item->name);
		game->player->xp += OBJ_DISCARD_EXP;
		return (1);
	} else {
		item_activat(game, item);
	}
	return (0);
}

int mouse_click(game_global_t *game, sfMouseButtonEvent event)
{
	inventory_t *inventory = game->invent->first;
	items_data_t *invent_item;
	sfVector2f pos;

	game->invent_item = NULL;
	pos = screen_to_world_click(game, event);
	while (inventory->name != NULL) {
		invent_item = inventory_get_items(game->items_data, inventory->name);
		if (pos.x < invent_item->x + 16 &&
		pos.x > invent_item->x - 16 &&
		pos.y < invent_item->y + 16 &&
		pos.y > invent_item->y - 16)
			which_click(game, event, invent_item);
		inventory = inventory->next;
		if (inventory == NULL)
			break;
	}
	return (0);
}