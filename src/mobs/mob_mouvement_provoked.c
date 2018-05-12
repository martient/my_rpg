/*
** EPITECH PROJECT, 2018
** mob_mouvement_provoked.c
** File description:
** function for enemy mouvement when its provoked by player
*/

#include "my_rpg.h"

static int is_player_close(game_global_t *game, mob_info_t *mob)
{
	player_info_t *player = game->player;

	if (!(player->x < (mob->x + 100) && player->x > (mob->x - 100)))
		return (0);
	if (!(player->y < (mob->y + 100) && player->y > (mob->y - 100)))
		return (0);
	return (1);
}	

static int is_between_offset(float point, float position, float offset)
{
	if (position < (point + offset) && position > (point - offset))
		return (1);
	return (0);
}

static int move_towards_player(game_global_t *game,
mob_info_t *mob, double delta_time)
{
	player_info_t *player = game->player;

	if (is_between_offset(player->x, mob->x, 10) &&
	is_between_offset(player->y, mob->y, 10))
		return (0);
	if (is_between_offset(player->x, mob->x, 10) != 1) {
		if (player->x > mob->x)
			mob->x += PLAYER_SPEED * delta_time;
		else
			mob->x -= PLAYER_SPEED * delta_time;
	}
	if (is_between_offset(player->y, mob->y, 10) != 1) {
		if (player->y > mob->y)
			mob->y += PLAYER_SPEED * delta_time;
		else
			mob->y -= PLAYER_SPEED * delta_time;
	}
	return (1);
}

int mob_move_provoked(game_global_t *game, mob_info_t *mob, double delta_time)
{
	player_info_t *player = game->player;

	if (is_player_close(game, mob))
		move_towards_player(game, mob, delta_time);
	return (0);
}

#include <criterion/criterion.h>

game_global_t *generate_fake_game_player(float x, float y)
{
	game_global_t *game = malloc(sizeof(game_global_t));
	player_info_t *player = malloc(sizeof(player_info_t));

	player->x = x;
	player->y = y;
	game->player = player;
	return (game);
}

Test(player_is_close, get_new_mouvement)
{
	game_global_t *game = generate_fake_game_player(100, 100);
	mob_info_t *mob = malloc(sizeof(mob_info_t));

	mob->x = 10.0;
	mob->y = 10.0;
	cr_assert_eq(is_player_close(game, mob), 1, "Fail");
	free(mob);
	free(game->player);
	free(game);
}

Test(move_mob, move_towards_player)
{
	game_global_t *game = generate_fake_game_player(100, 100);
	mob_info_t *mob = malloc(sizeof(mob_info_t));

	mob->x = 50;
	mob->y = 50;
	move_towards_player(game, mob, 1);
	cr_expect_eq(mob->x, 250, "Fail X");
	cr_expect_eq(mob->y, 250, "Fail Y");
}

Test(x_move_mob, move_towards_player)
{
	game_global_t *game = generate_fake_game_player(100, 100);
	mob_info_t *mob = malloc(sizeof(mob_info_t));

	mob->x = 50;
	mob->y = 100;
	move_towards_player(game, mob, 1);
	cr_expect_eq(mob->x, 250, "Fail X");
	cr_expect_eq(mob->y, 100, "Fail Y");
}

Test(y_move_mob, move_towards_player)
{
	game_global_t *game = generate_fake_game_player(100, 100);
	mob_info_t *mob = malloc(sizeof(mob_info_t));

	mob->x = 100;
	mob->y = 50;
	move_towards_player(game, mob, 1);
	cr_expect_eq(mob->y, 250, "Fail Y");
	cr_expect_eq(mob->x, 100, "Fail X");
}

Test(player_is_not_close, get_new_mouvement)
{
	game_global_t *game = generate_fake_game_player(1000, 1000);
	mob_info_t *mob = malloc(sizeof(mob_info_t));

	mob->x = 10.0;
	mob->y = 10.0;
	cr_assert_eq(is_player_close(game, mob), 0, "Fail");
	free(mob);
	free(game->player);
	free(game);
}

Test(between_offset, is_between_offset)
{
	float point = 10.0;
	float position = 7.0;
	float offset = 5.0;

	cr_assert_eq(is_between_offset(point, position, offset), 1, "Fail");
}

Test(not_between_offset, is_between_offset)
{
	float point = 10.0;
	float position = 4.0;
	float offset = 5.0;

	cr_assert_eq(is_between_offset(point, position, offset), 0, "Fail");
}
