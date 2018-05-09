/*
** EPITECH PROJECT, 2018
** main_event.c
** File description:
** event hub
*/

#include "my_rpg.h"

void keyboard_press_event(game_global_t *game, sfKeyEvent event)
{
	if (event.code == sfKeyI)
		game->inventory_show = (game->inventory_show == 0) ? 1 : 0;
	if (event.code == sfKeyEscape)
		pause_screen(game);
	if (event.code == sfKeyE)
		interact_obj(game);
}

void mouse_zoom(game_global_t *game, sfMouseWheelScrollEvent event)
{
	if (event.delta > 0 && game->zoom < 2)
		game->zoom += 0.5;
	else if (event.delta < 0 && game->zoom > 0.5)
		game->zoom -= 0.5;
}

int poll_events(game_global_t *game)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			rpg_player_save(game->player);
			rpg_inventory_save(game->invent);
			destroy_sound(game);
			sfRenderWindow_close(game->window);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
		if (event.type == sfEvtKeyPressed)
			keyboard_press_event(game, event.key);
		if (event.type == sfEvtMouseWheelScrolled)
			mouse_zoom(game, event.mouseWheelScroll);
		if (game->inventory_show == 1 && event.type == sfEvtMouseMoved)
			mouse_hover(game, event.mouseMove);
		if (game->inventory_show == 1 && event.type == sfEvtMouseButtonPressed)
			mouse_click(game, event.mouseButton);
	}
	return (0);
}

int analyse_event(game_global_t *game)
{
	double delta_time =
	sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;
	mob_info_t *mob = game->mob_deploy->first;

	while (mob) {
		if (mob->id != -1)
			mob_move_passive(game, mob, delta_time);
		mob = mob->next;
	}
	spell_cooldown(game, delta_time);
	quest_manager(game);
	poll_events(game);
	obj_cooldown(game, delta_time);
	key_event(game, delta_time);
	sfClock_restart(game->clock);
	return (0);
}
