/*
** EPITECH PROJECT, 2018
** fallen_quest.c
** File description:
** function for fallen quest line
*/

#include "my_rpg.h"

int fallen_killed_monster(player_info_t *player, int reset)
{
	int static count = 0;

	if (player->current_quest_id != 4)
		return (count);
	if (reset == -1)
		count = 0;
	if (reset == 1)
		count++;
	return (count);
}

int is_fallen_done(game_global_t *game)
{
	if (fallen_killed_monster(game->player, 0) != 5)
		return (1);
	fallen_killed_monster(game->player, -1);
	game->player->xp += 500;
	play_sound(game, "success");
	return (0);
}

int fallen_draw_quest(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos = {game->player->x - (game->width / 3),
	game->player->y - (game->height / 3)};

	texture = sfTexture_createFromFile(fallen_quest_url, NULL);
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