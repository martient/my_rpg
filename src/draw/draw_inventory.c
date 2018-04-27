/*
** EPITECH PROJECT, 2018
** draw_inventory.h
** File description:
** function to draw inventory
*/

#include "my_rpg.h"

void draw_item_box(game_global_t *game, items_data_t *invent_item)
{
	player_info_t *player = game->player;
	sfColor sfBrown = {182, 155, 76, 255};
	int info[5] = {my_strlen(invent_item->name) * 10, 70, 100, invent_item->x + 32, invent_item->y + 32};
	int text_info[3] = {invent_item->x + 32, invent_item->y + 32, 20};
	sfColor colors[2] = {sfRed, sfGreen};

	draw_bar(game, colors, info);
	engine_create_text(game, invent_item->name, text_info, sfWhite);
	text_info[1] += 32;
	engine_create_text(game, "!", text_info, sfWhite);
	sfRenderWindow_display(game->window);
}

static void draw_inventory_items(game_global_t *game)
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
		inventory_set_items(invent_item, pos.x, pos.y);
		sfSprite_setPosition(invent_item->sprite, pos);
		sfRenderWindow_drawSprite(game->window, invent_item->sprite, NULL);
		inventory = inventory->next;
		if (inventory == NULL)
			break;
	}
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
	draw_inventory_items(game);
	if (game->invent_item != NULL)
		draw_item_box(game, game->invent_item);
	return (0);
}