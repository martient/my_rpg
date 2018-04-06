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
#include "inventory.h"
#include "skill_tree.h"
#define GAME_NAME "Overlord Adventures"
#define DEFAULT_FRAME_RATE 60
#define START_SCREEN 0

#ifndef Z_MINIMUM
#define Z_MINIMUM -1
#endif

#ifndef Z_MAXIMUM
#define Z_MAXIMUM 2
#endif

#ifndef PLAYER_SPEED
#define PLAYER_SPEED 20
#endif

typedef struct player_info_t {
	sfView *camera;
	char *name;
	double x;
	double y;
	int zone;
	int health;
	int max_health;
	float power;
	int mana;
	double cd_q;
	double cd_w;
	double cd_e;
	double cd_r;
	double cd_a;
	int skill_point;
	int direction;
	int moving;
	sfSprite *sprite;
	sfTexture *texture;
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
	object_first_t *first;
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
	struct map_info_t *info_map;
	struct skills_t *tree;
} game_global_t;

game_global_t *__init__(void);
void engine_exit(game_global_t *global);
void draw_shim(game_global_t *game, sfColor color);
void draw_bar(game_global_t *game, sfColor colors[2], int *infos);
void draw_player(game_global_t *game);
char *rpg_map_load(char *filepath);
int rpg_json_map_init(object_first_t *info);
player_info_t *rpg_map_parsed(char *file_content);
game_global_t *__init__(void);
int draw(game_global_t *game, int *infos, int *infos2);
void update_screen_size(game_global_t *game);
int analyse_event(game_global_t *game);
void draw__(game_global_t *game);
void game_loop(game_global_t *game);
int main(int ac, char *argv[], char *env[]);
player_info_t *init_player(game_global_t *game);
int my_put_nbr(int nb);
int my_putstr(char *str);
int my_strcmp(char *str, char *str2);
char *my_strdup(char *str);
int my_strlen(char *str);
void key_event(game_global_t *game, double delta_time);
int rpg_init_global_info(object_first_t *info);
object_first_t *rpg_init_object_list(void);
int rpg_inject_object_list(object_first_t *info, const nx_json *data, int pos);
int rpg_inject_object_grass_list(object_first_t *info);
map_info_t *rpg_map_info(void);
int draw_element(game_global_t *game);
void player_move(game_global_t *game, double delta_time, int direction);
void draw_ui(game_global_t *game);
int draw_health(game_global_t *game);
int draw_box(game_global_t *game, char *text, int kill);
int draw_spell_cd_box(game_global_t *game, double percentage);
#endif /* !MY_RPG_H_ */
