/*
** EPITECH PROJECT, 2018
** draw_pause_screen.c
** File description:
** function to draw pause screen
*/

#include "my_rpg.h"

int draw_play_button(game_global_t *game)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f scale = {2 * (game->width / 800), 2 * (game->height / 600)};
	sfVector2f position =
	{(game->width / 2) - (108 * scale.x / 2), (game->height / 2)
	- (48 * scale.y / 2)};

	texture = sfTexture_createFromFile("./resources/ui/start_btn.png",
	NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, position);
	sfSprite_setScale(sprite, scale);
	sfRenderWindow_drawSprite(game->window, sprite, NULL);
	return (0);
}

void player_cam_reset(game_global_t *game)
{
	sfFloatRect cam = {0, 0, game->width, game->height};

	game->player->camera =  sfView_createFromRect(cam);
	sfView_reset(game->player->camera, cam);
	sfRenderWindow_setView(game->window, game->player->camera);
}

int draw_pause_screen(game_global_t *game)
{
	sfRenderWindow_clear(game->window, sfBlack);
	draw_play_button(game);
	draw_music_button(game);
	draw_sfx_button(game);
	sfRenderWindow_display(game->window);
	return (0);
}

void pause_screen(game_global_t *game)
{
	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		event_pause_screen(game);
		player_cam_reset(game);
		draw_pause_screen(game);
	}
}