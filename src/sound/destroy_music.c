/*
** EPITECH PROJECT, 2018
** destroy_sound
** File description:
** function to detroy sound
*/

#include "my_rpg.h"

int destroy_sound(game_global_t *game)
{
	sound_data_t *sound = game->sound->sound;
	sound_data_t *bck;

	while (sound) {
		sfSound_stop(sound->sound);
		sfSound_destroy(sound->sound);
		sfSoundBuffer_destroy(sound->buffer);
		bck = sound;
		sound = sound->next;
		free(bck);
	}
	return (0);
}