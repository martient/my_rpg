/*
** EPITECH PROJECT, 2018
** draw_hub.c
** File description:
** main 
*/

#include "my_rpg.h"

void draw__(game_global_t *game)
{
	sfRenderWindow_clear(game->window, sfWhite);
	draw_element(game);
	draw_ui(game);
	draw_spell_cd_box(game, 100);
	// draw_player(game);
	sfRenderWindow_display(game->window);	
}