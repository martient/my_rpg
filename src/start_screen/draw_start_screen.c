/*
** EPITECH PROJECT, 2018
** draw_start_screen.c
** File description:
** function to draw start screen
*/

#include "my_rpg.h"

int draw_start_button(game_global_t *game)
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

static void player_cam_reset(game_global_t *game)
{
	sfFloatRect cam = {0, 0, game->width, game->height};

	game->player->camera =  sfView_createFromRect(cam);
	sfView_reset(game->player->camera, cam);
	sfRenderWindow_setView(game->window, game->player->camera);
}

void draw_start_screen(game_global_t *game)
{
	int info[3] = {(game->width / 2) - ((my_strlen(GAME_NAME) / 4) * 36),
	(game->height / 2) - 150, 36};
	
	sfRenderWindow_clear(game->window, sfBlack);
	player_cam_reset(game);
	engine_create_text(game, GAME_NAME, info, sfRed);
	draw_start_button(game);
	sfRenderWindow_display(game->window);
}

void start_game_loop(game_global_t *game)
{
	only_play(game, "main_menu");
	sfClock_restart(game->clock);
	sfRenderWindow_setFramerateLimit(game->window, 60);
	while (sfRenderWindow_isOpen(game->window)) {
		event_start_screen(game);
		draw_start_screen(game);
	}
}