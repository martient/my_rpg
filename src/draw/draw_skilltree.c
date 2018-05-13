/*
** EPITECH PROJECT, 2018
** draw_skill_tree.c
** File description:
** function to draw skill_tree
*/

#include "my_rpg.h"

void draw_sk_level(game_global_t *game, sfVector2f position, int level)
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f scale =
	{1.5 * (game->width / 800), 1.5 * (game->height / 600)};

	sprite = sfSprite_create();
	texture =
	sfTexture_createFromFile("./resources/sprites/skill_tree/level.png",
	NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	position.x += 10;
	for (int i = 0; i < level; i++) {
		position.x += 32 * scale.x;
		sfSprite_setPosition(sprite, position);
		sfRenderWindow_drawSprite(game->window, sprite, NULL);
	}
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
}

void draw_skills(game_global_t *game)
{
	st_draw_strength(game);
	st_draw_inventory(game);
	st_draw_health(game);
	st_draw_attack(game);
}

int draw_skill_tree(game_global_t *game)
{
	player_info_t *player = game->player;
	sfColor sfBrown = {182, 155, 76, 255};
	int invent_x = player->x - (game->width / 4);
	int len_1 = game->width / 2;
	int len_2 = game->height  - (game->height / 4);
	int len_3 = player->y - (game->height / 4);
	int len_4 = player->x - ((my_strlen(SKILL_TREE) * 16) / 2);
	int info[5] = {len_1, len_2, 100, invent_x, len_3};
	int text_info[3] = {len_4, player->y - (game->height / 4), 32};
	sfColor colors[2] = {sfRed, sfBrown};

	draw_bar(game, colors, info);
	draw_skills(game);
	engine_create_text(game, SKILL_TREE, text_info, sfWhite);
	return (0);
}