/*
** EPITECH PROJECT, 2018
** draw_inventory.h
** File description:
** function to draw inventory
*/

#include "my_rpg.h"

static int draw_inventory_items(game_global_t *game)
{
	inventory_t *inventory = game->invent->first;
	items_data_t *invent_item;
	sfVector2f pos;
	int x = 32;
	int y = 64;

	while (inventory->name != NULL) {
		invent_item = inventory_get_items(game->items_data, inventory->name);
		pos.x = (game->player->x) - (game->width  / 4) + x;
		pos.y = (game->player->y) - (game->height / 4) + y;
		x += 64;
		if (x > (game->player->x) + (game->width  / 4)) {
			y += 64;
			x = 32;
		}
		sfSprite_setPosition(invent_item->sprite, pos);
		sfRenderWindow_drawSprite(game->window, invent_item->sprite, NULL);
		inventory = inventory->next;
		if (inventory == NULL)
			return (1);
	}
	return (0);
}

int draw_inventory(game_global_t *game)
{
	player_info_t *player = game->player;
	sfColor sfBrown = {182, 155, 76, 255};
	int inventory_x = player->x - (game->width / 4);
	int info[5] = {game->width / 2, game->height / 2, 100, inventory_x, player->y - (game->height / 4)};
	int text_info[3] = {player->x - ((my_strlen(INVENTORY) * 16) / 2), player->y - (game->height / 4), 32};
	sfColor colors[2] = {sfRed, sfBrown};

	draw_bar(game, colors, info);
	engine_create_text(game, INVENTORY, text_info, sfWhite);
	// draw_inventory_items(game);
	return (0);
}