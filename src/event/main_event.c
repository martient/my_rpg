/*
** EPITECH PROJECT, 2018
** main_event.c
** File description:
** event hub
*/

#include "my_rpg.h"

void keyboard_press_event(game_global_t *game, sfKeyEvent event)
{
	if (event.code == INVENTORY_KEY)
		game->inventory_show = (game->inventory_show == 0) ? 1 : 0;
	if (event.code == PAUSE_KEY)
		pause_screen(game);
	if (event.code == INTERACT_KEY)
		interact_obj(game);
	if (event.code == QUEST_KEY) {
		if (game->player->state == 2 || game->player->state == 0)
			game->player->state = game->player->current_quest_id;
		else
			game->player->state = 0;
	}
}

void reset_quest_draw(game_global_t *game)
{
	if (game->player->state != 0 && game->player->state != 2)
		game->player->state = 0;
}

int handle_event(game_global_t *game, sfEvent event)
{
	if (event.type == sfEvtResized)
		update_screen_size(game);
	if (event.type == sfEvtKeyPressed)
		keyboard_press_event(game, event.key);
	if (event.type == sfEvtMouseButtonPressed)
		reset_quest_draw(game);
	if (game->inventory_show == 1 && event.type == sfEvtMouseMoved)
		mouse_hover(game, event.mouseMove);
	if (game->inventory_show == 1 &&
	event.type == sfEvtMouseButtonPressed)
		mouse_click(game, event.mouseButton);
	return (0);
}

int poll_events(game_global_t *game)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			exit_game(game);
			return (0);
		}
		handle_event(game, event);
	}
	return (0);
}

int analyse_event(game_global_t *game)
{
	double delta_time =
	sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;
	mob_info_t *mob = game->mob_deploy->first;

	sfClock_restart(game->clock);
	while (mob) {
		if (mob->id != -1)
			mob_move_passive(game, mob, delta_time);
		mob = mob->next;
	}
	mobs_basic_attack(game);
	spell_cooldown(game, delta_time);
	quest_manager(game);
	poll_events(game);
	level_up(game);
	obj_cooldown(game, delta_time);
	key_event(game, delta_time);
	return (0);
}
