/*
** EPITECH PROJECT, 2018
** music_manager.c
** File description:
** funciton to handle music in pause menu
*/

#include "my_rpg.h"

int check_music_status(game_global_t *game, int reset)
{
	static int status = 1;

	if (reset == 1)
		status *= -1;
	if (status == 1 && reset == 1) {
		game->sound->music_volume = 100;
		update_sound(game);
	} else if (status == -1 && reset == 1){
		game->sound->music_volume = 0;
		update_sound(game);
	}
	return (status);
}

int draw_music_button_on(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f scale = {2 * (game->width / 800), 2 * (game->height / 600)};
	sfVector2f position =
	{48 * scale.x, game->height - (48 * scale.y * 2)};

	texture = sfTexture_createFromFile("./resources/ui/music_on.png",
	NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, position);
	sfSprite_setScale(sprite, scale);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	return (0);
}

int draw_music_button_off(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f scale = {2 * (game->width / 800), 2 * (game->height / 600)};
	sfVector2f position =
	{48 * scale.x, game->height - (48 * scale.y * 2)};

	texture = sfTexture_createFromFile("./resources/ui/music_off.png",
	NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, position);
	sfSprite_setScale(sprite, scale);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	return (0);
}

void draw_music_button(game_global_t *game)
{
	if (check_music_status(game, 0) == 1)
		draw_music_button_on(game);
	else
		draw_music_button_off(game);
}