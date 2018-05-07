/*
** EPITECH PROJECT, 2018
** sound_init.c
** File description:
** function to init sound
*/

#include "my_rpg.h"
#include "sound.h"

sound_data_t *add_sound(sound_data_t *head, int type, char *path, char *name)
{
	sound_data_t *new_sound = malloc(sizeof(sound_data_t));
	
	new_sound->sound = sfSound_create();
	new_sound->buffer = sfSoundBuffer_createFromFile(path);
	sfSound_setBuffer(new_sound->sound, new_sound->buffer);
	new_sound->path = my_strdup(path);
	new_sound->name = my_strdup(name);
	new_sound->type = type;
	new_sound->next = head;
	return (new_sound);
}

int init_sound(game_global_t *game)
{
	game->sound = malloc(sizeof(sound_data_t));

	if (game->sound == NULL)
		return (1);
	game->sound->music_volume = 1;
	game->sound->sfx_volume = 1;
	game->sound->sound = NULL;
	game->sound->sound = add_sound(game->sound->sound, music,
	"./resources/sounds/music/IntroMusic.ogg", "main_menu");
	game->sound->sound = add_sound(game->sound->sound, music,
	"./resources/sounds/music/MainMusic.ogg", "main_music");
	game->sound->sound = add_sound(game->sound->sound, sfx,
	"./resources/sounds/sfx/eating_noise.ogg", "eating");
	return (0);
}