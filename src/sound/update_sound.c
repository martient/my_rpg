/*
** EPITECH PROJECT, 2018
** update_sound.c
** File description:
** funciton to update osund volume
*/

#include "my_rpg.h"

void update_sound(game_global_t *game)
{
	sound_info_t *info = game->sound;
	sound_data_t *sound = game->sound->sound;

	while (sound) {
		if (sound->type == music)
			sfSound_setVolume(sound->sound, info->music_volume);
		if (sound->type == sfx)
			sfSound_setVolume(sound->sound, info->sfx_volume);
		sound = sound->next;
	}
}