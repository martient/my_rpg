/*
** EPITECH PROJECT, 2018
** skill_tree.c
** File description:
** Header file that define all skill tree constants value
*/

#ifndef SKILL_TREE_H_
	#define SKILL_TREE_H_

#include "knight_skills.h"

#ifndef FIRST_LIFE_H_
#define FIRST_LIFE_H_ 100
#endif

#ifndef SECOND_LIFE_H_
#define SECOND_LIFE_H_ 125
#endif

#ifndef THIRD_LIFE_H_
#define THIRD_LIFE_H_ 150
#endif

#ifndef FOURTH_LIFE_H_
#define FOURTH_LIFE_H_ 175
#endif

#ifndef FIFTH_LIFE_H_
#define FIFTH_LIFE_H_ 200
#endif

#ifndef LIFE_UPGRADE_COST_H_
#define LIFE_UPGRADE_COST_H_ 2
#endif

#ifndef FIRST_POWER_H_
#define FIRST_POWER_H_ 1
#endif

#ifndef SECOND_POWER_H_
#define SECOND_POWER_H_ 1.25
#endif

#ifndef THIRD_POWER_H_
#define THIRD_POWER_H_ 1.5
#endif

#ifndef FOURTH_POWER_H_
#define FOURTH_POWER_H_ 1.75
#endif

#ifndef FIFTH_POWER_H_
#define FIFTH_POWER_H_ 2
#endif

#ifndef POWER_UPGRADE_COST_H_
#define POWER_UPGRADE_COST_H_ 2
#endif

typedef struct skills_t {
	int attack_level;
	int life_level;
	int power_level;
} skills_t;

#endif /* !SKILL_TREE_H_ */
