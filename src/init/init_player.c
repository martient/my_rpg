/*
** EPITECH PROJECT, 2018
** init_player.c
** File description:
** funciton to initialise player
*/

#include "my_rpg.h"

static void init_player_sprite(player_info_t *player)
{
	sfTexture *player_texture;
	sfSprite *player_sprite;
	sfIntRect spritesheet_rect = {0, 0, 32, 32};
	sfVector2f pos = {player->x, player->y};

	player_texture = sfTexture_createFromFile("./resources/sprite/knight.png", NULL);
	player_sprite = sfSprite_create();
	sfSprite_setTexture(player_sprite, player_texture, sfTrue);
	sfSprite_setTextureRect(player_sprite, spritesheet_rect);
	sfSprite_setPosition(player_sprite, pos);
	player->sprite = player_sprite;
	player->texture = player_texture;
	player->moving = 0;
}

player_info_t *init_player(game_global_t *game)
{
	char *file_content = rpg_map_load("./resources/player.json");
	player_info_t *player = malloc(sizeof(player_info_t));
	const nx_json* json = nx_json_parse(file_content, 0);
	
	if (json && player) {
		player->name =  nx_json_get(json, "name")->text_value;
		player->x = nx_json_get(json, "x")->dbl_value;
		player->y = nx_json_get(json, "y")->dbl_value;
		player->zone = nx_json_get(json, "zone")->int_value;
		player->health = nx_json_get(json, "pv")->int_value;
		player->mana = nx_json_get(json, "mana")->int_value;
		player->skill_point = nx_json_get(json, "skill_point")->int_value;
		player->direction = nx_json_get(json, "direction")->int_value;
		player->cd_q = 0;
		player->cd_w = 0;
		player->cd_e = 0;
		player->cd_r = 0;
		player->cd_a = 0;
		init_player_sprite(player);
		game->player = player;
		return (player);
	}
	return (NULL);
}