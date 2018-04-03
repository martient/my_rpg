/*
** EPITECH PROJECT, 2018
** init_knight_skill_tree.c
** File description:
** Function that initialize the knight's skill tree
*/

#include "my_rpg.h"

skills_t *init_skill_tree(void)
{
	struct skills_t *tree = malloc(sizeof(tree));

	tree->attack_level = 1;
	tree->life_level = 1;
	tree->power_level = 1;
	return (tree);
}