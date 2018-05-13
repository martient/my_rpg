/*
** EPITECH PROJECT, 2018
** draw_skilltree_branches.c
** File description:
** functiont to draw skill tree branches
*/

#include "my_rpg.h"

void st_draw_strength(game_global_t *game)
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f scale =
	{1.5 * (game->width / 800), 1.5 * (game->height / 600)};
	sfVector2f position = {(game->player->x) - (game->width  / 4)
	- (32 * scale.x / 2) + (32 * scale.x),
	(game->player->y) - (game->height / 4) -
	(32 * scale.y / 2) + (32 * scale.y * 2)};

	texture =
	sfTexture_createFromFile("./resources/sprites/skill_tree/power.png",
	NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setScale(sprite, scale);
	sfSprite_setPosition(sprite, position);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	draw_sk_level(game, position, game->tree->power_level);
}

void st_draw_inventory(game_global_t *game)
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f scale =
	{1.5 * (game->width / 800), 1.5 * (game->height / 600)};
	sfVector2f position =
	{(game->player->x) - (game->width  / 4) -
	(32 * scale.x / 2) + (32 * scale.x),
	(game->player->y) - (game->height / 4) -
	(32 * scale.y / 2) + (32 * scale.y * 4)};
	texture =
	sfTexture_createFromFile(
	"./resources/sprites/skill_tree/inventory.png", NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setScale(sprite, scale);
	sfSprite_setPosition(sprite, position);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	draw_sk_level(game, position, game->tree->invent_size);
}

void st_draw_health(game_global_t *game)
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f scale =
	{1.5 * (game->width / 800), 1.5 * (game->height / 600)};
	sfVector2f position =
	{(game->player->x) - (game->width  / 4) -
	(32 * scale.x / 2) + (32 * scale.x),
	(game->player->y) - (game->height / 4) -
	(32 * scale.y / 2) + (32 * scale.y * 6)};
	texture =
	sfTexture_createFromFile("./resources/sprites/skill_tree/life.png",
	NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setScale(sprite, scale);
	sfSprite_setPosition(sprite, position);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	draw_sk_level(game, position, game->tree->life_level);
}

void st_draw_attack(game_global_t *game)
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f scale =
	{1.5 * (game->width / 800), 1.5 * (game->height / 600)};
	sfVector2f position =
	{(game->player->x) - (game->width  / 4) -
	(32 * scale.x / 2) + (32 * scale.x),
	(game->player->y) - (game->height / 4) -
	(32 * scale.y / 2) + (32 * scale.y * 8)};
	texture =
	sfTexture_createFromFile(
	"./resources/sprites/skill_tree/attack.png", NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setScale(sprite, scale);
	sfSprite_setPosition(sprite, position);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	draw_sk_level(game, position, game->tree->attack_level);
}