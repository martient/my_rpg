/*
** EPITECH PROJECT, 2018
** my_rpg.h
** File description:
** General Header file
*/

#ifndef MY_RPG_H_
	#define MY_RPG_H_
#include <SFML/Graphics.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "nxjson.h"
#include "my.h"
#include "inventory.h"
//#include "skill_tree.h"
#define GAME_NAME "Overlord Adventures"
#define DEFAULT_FRAME_RATE 60
#define START_SCREEN 0

typedef struct player_info_t {
	sfView *camera;
	char *name;
	double x;
	double y;
	int zone;
	int health;
	int mana;
	double cd_q;
	double cd_w;
	double cd_e;
	double cd_r;
	double cd_a;
	int skill_point;
	int rotate;
} player_info_t;


typedef struct object_info_t object_info_t;
struct object_info_t {
	char *name;
	int x;
	int y;
	int z;
	int collider;
	int type;
	int visible;
	//Collision call back;
	sfTexture *texture;
	sfSprite *sprite;
	object_info_t *next;
};

typedef struct object_first_t object_first_t;
struct object_first_t {
	object_info_t *first;
};

typedef struct map_info_t map_info_t;
struct map_info_t {
	char *name;
	int width;
	int height;
	int start_x;
	int start_y;
	object_first_t first;
};

typedef struct game_global_t {
	sfRenderWindow *window;
	sfClock *clock;
	int height;
	int width;
	int screen_id;
	int frame_rate;
	int state;
	sfFont *font;
	struct player_info_t *player;
	struct inventory_list *invent;
	struct skills_t *tree;
} game_global_t;

game_global_t *__init__(void);
void engine_exit(game_global_t *global);
int draw_element(game_global_t *game, object_info_t *obj);
void draw_shim(game_global_t *game, sfColor color);
void draw_bar(game_global_t *game, sfColor colors[2], int *infos);
void draw_player(game_global_t *game);
char *rpg_map_load(char *filepath);
int rpg_json_map_init(object_first_t *info);
player_info_t *rpg_map_parsed(char *file_content);
inventory *new_ivnt_obj(char *path, char *name);
int add_inventory(struct inventory_list *ivnt, char *name);
int del_beginning(inventory_list *ivnt, inventory *del_list);
int del_end(inventory *del, inventory *previous);
int del_inventory(struct inventory_list *ivnt, char *name);
int print_inventory(inventory_list *ivnt);
int get_inventory_size(struct inventory_list *ivnt);
int inventory_new_obj(struct inventory_list_t *list, char *name);
int inventory_del_obj(struct inventory_list_t *list, char *name);
inventory_list *init_inventory(void);
game_global_t *__init__(void);
int draw(game_global_t *game, int *infos, int *infos2);
void update_screen_size(game_global_t *game);
int analyse_event(game_global_t *game);
void draw__(game_global_t *game);
void game_loop(game_global_t *game);
int main(int ac, char *argv[], char *env[]);

#endif /* !MY_RPG_H_ */
