/*
** EPITECH PROJECT, 2018
** player.h
** File description:
** Header file for the player struct
*/

#ifndef PLAYER_H_
	#define PLAYER_H_

#include <SFML/Graphics.h>

typedef struct object_info_t object_info_t;
typedef struct interaction_event_t {
	int type;
	object_info_t *obj;
} interaction_event_t;

typedef struct player_info_t {
	sfView *camera;
	char *name;
	double x;
	double y;
	double speed;
	int zone;
	int health;
	int max_health;
	float power;
	int mana;
	double spell_duration[5];
	double spell_cd[5];
	int skill_point;
	int direction;
	int moving;
	int current_quest_id;
	int xp;
	int level;
	interaction_event_t *event;
	sfSprite *sprite;
	sfTexture *texture;
} player_info_t;

#endif /* !PLAYER_H_ */
