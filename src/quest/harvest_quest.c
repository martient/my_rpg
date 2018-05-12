/*
** EPITECH PROJECT, 2018
** harvest_quest.c
** File description:
** function for handling harvest quest
*/

#include "my_rpg.h"

int is_harvest_done(game_global_t *game)
{
	if (get_item_quantity(game, "Carrots") < 5)
		return (1);
	if (get_item_quantity(game, "Mushrooms") < 2)
		return (1);
	if (get_item_quantity(game, "Egg Plant") < 3)
		return (1);
	for (int i = 0; i < 5; i++)
		inventory_del_obj(game->invent, "Carrots");
	for (int i = 0; i < 2; i++)
		inventory_del_obj(game->invent, "Mushrooms");
	for (int i = 0; i < 3; i++)
		inventory_del_obj(game->invent, "Egg Plant");
	play_sound(game, "success");
	return (0);
}

int harvest_draw_quest(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos = {game->player->x - (game->width / 3),
	game->player->y - (game->height / 3)};

	texture = sfTexture_createFromFile(harvest_quest_url, NULL);
	if (texture == NULL) {
		my_putstr("Failed to get quest ressources\n");
		return (1);
	}
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	return (0);
}