/*
** EPITECH PROJECT, 2018
** skill_tree.c
** File description:
** Header file that define all skill tree constants value
*/

#ifndef SKILL_TREE_H_
	#define SKILL_TREE_H_

#include "knight_skills.h"

#ifndef FIRST_LIFE
#define FIRST_LIFE 100
#endif

#ifndef SECOND_LIFE
#define SECOND_LIFE 125
#endif

#ifndef THIRD_LIFE
#define THIRD_LIFE 150
#endif

#ifndef FOURTH_LIFE
#define FOURTH_LIFE 175
#endif

#ifndef FIFTH_LIFE
#define FIFTH_LIFE 200
#endif

#ifndef LIFE_UPGRADE_COST
#define LIFE_UPGRADE_COST 2
#endif

#ifndef FIRST_POWER
#define FIRST_POWER 1
#endif

#ifndef SECOND_POWER
#define SECOND_POWER 1.25
#endif

#ifndef THIRD_POWER
#define THIRD_POWER 1.5
#endif

#ifndef FOURTH_POWER
#define FOURTH_POWER 1.75
#endif

#ifndef FIFTH_POWER
#define FIFTH_POWER 2
#endif

#ifndef POWER_UPGRADE_COST
#define POWER_UPGRADE_COST 2
#endif

#ifndef INVENTORY_UPGRADE_COST
#define INVENTORY_UPGRADE_COST 2
#endif

typedef struct skills_t {
	int attack_level;
	int life_level;
	int power_level;
	int invent_size;
} skills_t;

#endif /* !SKILL_TREE_H_ */