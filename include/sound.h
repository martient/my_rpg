/*
** EPITECH PROJECT, 2018
** sound.h
** File description:
** header file for sound
*/

#ifndef SOUND_H_
	#define SOUND_H_

#include <SFML/Audio.h>

typedef struct sound_data_t sound_data_t;
struct sound_data_t {
	int type;
	char *name;
	char *path;
	sfSound *sound;
	sfSoundBuffer *buffer;
	struct sound_data_t *next;
};

typedef struct sound_info_t sound_info_t;
struct sound_info_t {
	int music_volume;
	int sfx_volume;
	struct sound_data_t *sound;
};

enum sound_type {
	music,
	sfx
};
#endif /* !SOUND_H_ */
