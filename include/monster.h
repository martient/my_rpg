/*
** EPITECH PROJECT, 2018
** monster.h
** File description:
** Epitech project
*/

typedef struct spawn_mob_t spawn_mob_t;
struct spawn_mob_t {
	int id;
	int y;
	int x;
	int type;
	int rate;
	spawn_mob_t *next;
};

typedef struct spawn_first_t spawn_first_t;
struct spawn_first_t {
	spawn_mob_t *first;
};

typedef struct mob_info_t mob_info_t;
struct mob_info_t {
	int id;
	int y;
	int x;
	int type;
	int rate;
	mob_info_t *next;
};

typedef struct mob_first_t mob_first_t;
struct mob_first_t {
	mob_info_t *first;
};
