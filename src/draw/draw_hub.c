/*
** EPITECH PROJECT, 2018
** draw_hub.c
** File description:
** main 
*/

#include "my_rpg.h"

static void player_cam(game_global_t *game)
{
	sfVector2f pos = {game->player->x + (39/2), game->player->y + (39/2)};
	sfFloatRect cam = {0, 0, game->width, game->height};

	game->player->camera =  sfView_createFromRect(cam);
	sfView_setCenter(game->player->camera, pos);
	sfView_zoom(game->player->camera, game->zoom);
	sfRenderWindow_setView(game->window, game->player->camera);
}

void draw__(game_global_t *game)
{
	sfRenderWindow_clear(game->window, sfBlack);
	draw_element(game);
	draw_ui(game);
	draw_inventory(game);
	draw_spell_cd_box(game, 100);
	player_check_interaction(game);
	player_cam(game);
	sfRenderWindow_display(game->window);	
}