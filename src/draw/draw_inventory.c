/*
** EPITECH PROJECT, 2018
** draw_inventory.h
** File description:
** function to draw inventory
*/

#include "my_rpg.h"

void draw_item_box(game_global_t *game, items_data_t *i)
{
	sfColor sfBrown = {182, 155, 76, 255};
	char *quantity;
	int info[5] = {my_strlen(i->name) * 10, 70, 100, i->x + 32, i->y + 32};
	int text_info[3] = {i->x + 32, i->y + 32, 20};
	sfColor colors[2] = {sfRed, sfBrown};

	draw_bar(game, colors, info);
	engine_create_text(game, i->name, text_info, sfWhite);
	text_info[1] += 32;
	quantity = int_to_string(inventory_get_count(game, i->name));
	engine_create_text(game, quantity, text_info, sfWhite);
	sfRenderWindow_display(game->window);
}

void draw_one_item(items_data_t *item, sfVector2f pos, game_global_t *game)
{
	inventory_set_items(item, pos.x, pos.y);
	sfSprite_setPosition(item->sprite, pos);
	sfRenderWindow_drawSprite(game->window, item->sprite, NULL);
}

static void draw_inventory_items(game_global_t *game)
{
	inventory_t *invent = game->invent->first;
	items_data_t *item;
	sfVector2f pos;
	int x = 32;
	int y = 64;

	while (invent->name != NULL) {
		item = inventory_get_items(game->items_data, invent->name);
		pos.x = (game->player->x) - (game->width  / 4) + x;
		pos.y = (game->player->y) - (game->height / 4) + y;
		x += 64;
		if (x > (game->player->x) + (game->width  / 4)) {
			y += 64;
			x = 32;
		}
		draw_one_item(item, pos, game);
		invent = invent->next;
		if (invent == NULL)
			break;
	}
}

int draw_inventory(game_global_t *game)
{
	player_info_t *player = game->player;
	sfColor sfBrown = {182, 155, 76, 255};
	int invent_x = player->x - (game->width / 4);
	int len_1 = game->width / 2;
	int len_2 = game->height / 2;
	int len_3 = player->y - (game->height / 4);
	int len_4 = player->x - ((my_strlen(INVENTORY) * 16) / 2);
	int info[5] = {len_1, len_2, 100, invent_x, len_3};
	int text_info[3] = {len_4, player->y - (game->height / 4), 32};
	sfColor colors[2] = {sfRed, sfBrown};

	draw_bar(game, colors, info);
	engine_create_text(game, INVENTORY, text_info, sfWhite);
	draw_inventory_items(game);
	if (game->invent_item != NULL)
		draw_item_box(game, game->invent_item);
	return (0);
}