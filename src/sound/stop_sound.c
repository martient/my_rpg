/*
** EPITECH PROJECT, 2018
** stop_sound
** File description:
** functions to stop sound
*/

#include "my_rpg.h"

int stop_all_music(game_global_t *game)
{
	sound_data_t *sound = game->sound->sound;

	while (sound) {
		if (sound->type == music) {
			sfSound_stop(sound->sound);
		}
		sound = sound->next;
	}
	return (0);
}

int stop_sound(game_global_t *game, char *name)
{
	sound_data_t *sound = game->sound->sound;

	while (sound) {
		if (my_strcmp(name, sound->name) == 0) {
			sfSound_stop(sound->sound);
			return (1);
		}
		sound = sound->next;
	}
	my_putstr("Failed to find sound\n");
	return (0);
}