/*
** EPITECH PROJECT, 2018
** draw_quest_message.c
** File description:
** function to draw user getting quest from npg
*/

#include "global.h"
#include "text.h"
#include "player.h"
#include "lib.h"

static void draw_quest_msg_box(game_global_t *game)
{
	int info[3] = {32, 64, 16};

	engine_create_text(game, "Help...", info, sfWhite);
}

int draw_quest_message(game_global_t *game)
{
	player_info_t *player = game->player;
	sfColor sfBrown = {182, 155, 76, 255};
	int inventory_x = player->x - (game->width / 4);
	int info[5] = {game->width / 2, game->height / 2, 100, inventory_x, player->y - (game->height / 4)};
	int text_info[3] = {player->x - ((my_strlen(QUEST) * 16) / 2), player->y - (game->height / 4), 32};
	sfColor colors[2] = {sfRed, sfBrown};

	draw_bar(game, colors, info);
	engine_create_text(game, QUEST, text_info, sfWhite);
	draw_quest_msg_box(game);
	return (0);
}