/*
** EPITECH PROJECT, 2018
** play_sound
** File description:
** function to play sound
*/

#include "my_rpg.h"
#include "sound.h"

int check_sound(sound_data_t *sound, sound_info_t *info)
{
	if (sfSound_getStatus(sound->sound) == sfPlaying) {
		return (0);
	}
	sfSound_play(sound->sound);
	sfSound_setVolume(sound->sound,100 *
	((sound->type == music) ? info->music_volume : info->sfx_volume));
	return (1);
}

int play_sound(game_global_t *game, char *name)
{
	sound_data_t *sound = game->sound->sound;
	sound_info_t *info = game->sound;

	while (sound) {
		if (my_strcmp(name, sound->name) == 0) {
			check_sound(sound, info);
			return (1);
		}
		sound = sound->next;
	}
	my_putstr("Failed to play sound\n");
	return (0);
}

int only_play(game_global_t *game, char *name)
{
	sound_data_t *sound = game->sound->sound;
	sound_info_t *info = game->sound;

	while (sound) {
		if (my_strcmp(name, sound->name) == 0) {
			check_sound(sound, info);
		} else {
			sfSound_stop(sound->sound);
		}
		sound = sound->next;
	}
	return (0);
}