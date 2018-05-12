/*
** EPITECH PROJECT, 2018
** event_pause_screen.c
** File description:
** function to hande pause screen events
*/

#include "my_rpg.h"

static int check_play_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f scale = {2 * (game->width / 800), 2 * (game->height / 600)};
	sfVector2f position =
	{(game->width / 2) - (108 * scale.x / 2),
	(game->height / 2) - (48 * scale.y / 2)};

	if (event.button == sfMouseLeft)
		if (event.x > position.x &&
		event.x < position.x + (108 * scale.x) &&
		event.y > position.y &&
		event.y < position.y + (48 * scale.y))
			game_loop(game);
	return (0);
}

static int check_music_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f scale = {2 * (game->width / 800), 2 * (game->height / 600)};
	sfVector2f position =
	{48 * scale.x, game->height - (48 * scale.y * 2)};

	if (event.button == sfMouseLeft)
		if (event.x > position.x &&
		event.x < position.x + (48 * scale.x) &&
		event.y > position.y &&
		event.y < position.y + (48 * scale.y))
			check_music_status(game, 1);
	return (0);
}

static int check_sfx_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f scale = {2 * (game->width / 800), 2 * (game->height / 600)};
	sfVector2f position =
	{game->width - (48 * scale.x * 2), game->height - (48 * scale.y * 2)};

	if (event.button == sfMouseLeft)
		if (event.x > position.x &&
		event.x < position.x + (48 * scale.x) &&
		event.y > position.y &&
		event.y < position.y + (48 * scale.y))
			check_sfx_status(game, 1);
	return (0);
}

static void keyboard_press_event(game_global_t *game, sfKeyEvent event)
{
	if (event.code == sfKeyEscape)
		game_loop(game);
}

int event_pause_screen(game_global_t *game)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game->window);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
		if (event.type == sfEvtKeyPressed)
			keyboard_press_event(game, event.key);
		if (event.type == sfEvtMouseButtonPressed) {
			check_play_click(game, event.mouseButton);
			check_sfx_click(game, event.mouseButton);
			check_music_click(game, event.mouseButton);
		}
	}
	return (0);
}