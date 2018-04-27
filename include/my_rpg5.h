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
#include <time.h>
#include "keyboard.h"
#include "text.h"
#include "nxjson.h"
#include "inventory.h"
#include "skill_tree.h"
#include "monster.h"
#define GAME_NAME "Overlord Adventures"
#define DEFAULT_FRAME_RATE 60
#define START_SCREEN 0

#ifndef Z_MINIMUM
#define Z_MINIMUM -1
#endif

#ifndef Z_MAXIMUM
#define Z_MAXIMUM 5
#endif

#ifndef PLAYER_SPEED
#define PLAYER_SPEED 200
#endif

typedef struct items_data_s items_data_t;
struct items_data_s {
	int id;
	char *name;
	int type;
	float stats;
	int x;
	int y;
	sfTexture *texture;
	sfSprite *sprite;
	items_data_t *next;
};

typedef struct items_data_first_t items_data_first_t;
struct items_data_first_t {
	items_data_t *first;
};

typedef struct mob_data_t mob_data_t;
struct mob_data_t {
	int id;
	char *name;
	float attack_base;
	float attack_grow;
	float healt_base;
	float healt_grow;
	float armor_base;
	float armor_grow;
	float speed;
	sfTexture *texture;
	sfSprite *sprite;
	mob_data_t *next;
};

typedef struct mob_data_first_t mob_data_first_t;
struct mob_data_first_t {
	mob_data_t *first;
};

typedef struct spawn_mob_t spawn_mob_t;
struct spawn_mob_t {
	int id;
	int y;
	int x;
	int type;
	int rate;
	int size;
	spawn_mob_t *next;
};

typedef struct spawn_first_t spawn_first_t;
struct spawn_first_t {
	spawn_mob_t *first;
};

typedef struct mob_info_t mob_info_t;
struct mob_info_t {
	int id;
	float y;
 	float x;
	int type;
	int agressive;
	int level;
	double health;
	sfSprite *sprite;
	spawn_mob_t *spawn;
	mob_info_t *next;
};

typedef struct mob_first_t mob_first_t;
struct mob_first_t {
	mob_info_t *first;
};

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
	interaction_event_t *event;
	sfSprite *sprite;
	sfTexture *texture;
} player_info_t;

struct object_info_t {
	char *name;
	int x;
	int y;
	int z;
	int collider;
	int type;
	int visible;
	double cooldown;
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
	double zoom;
	int inventory_show;
	sfFont *font;
	struct player_info_t *player;
	inventory_list_t *invent;
	struct map_info_t *info_map;
	struct skills_t *tree;
	struct spawn_first_t *mob_spawn;
	struct mob_first_t *mob_deploy;
	struct mob_data_first_t *mob_data;
	struct items_data_first_t *items_data;
	items_data_t *invent_item;
} game_global_t;

items_data_first_t *rpg_items_data_init(void);
int rpg_init_link_list_items_data(items_data_first_t *first);
int rpg_json_init_items_data(items_data_first_t *first);
int rpg_items_data_inject(items_data_first_t *first, char **string, int *data,
float stats);
items_data_t *inventory_get_items(items_data_first_t *info,
char *target);
int inventory_set_items(items_data_t *info, int x, int y);

int rpg_mob_generator(spawn_first_t *spawn, mob_data_first_t *data,
	mob_first_t *mobs, player_info_t *player);
spawn_first_t *rpg_spawn_init(void);
int rpg_spawn_remove(spawn_first_t *first);
int rpg_spawn_init_list(spawn_first_t *first);
int rpg_spawn_inject(spawn_first_t *first, int *data);
int rpg_spawn_remove(spawn_first_t *first);
int rpg_json_init_spawn(spawn_first_t *first);
mob_data_first_t *rpg_mob_data_init(void);
int rpg_mob_data_inject(mob_data_first_t *first, float *data, int id,
	char *name);
int rpg_mob_data_remove(mob_data_first_t *first);
int rpg_mob_data_init_list(mob_data_first_t *first);
int rpg_json_init_mob_data(mob_data_first_t *first);
int rpg_mob_data_tex_inject(mob_data_first_t *first, char *pathfile);

mob_first_t *rpg_mob_init(void);


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
char *my_strdup(char const *str);
int my_strlen(char const *str);
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
void activate_spell(game_global_t *game, int spell);
void spell_cooldown(game_global_t *game, double delta_time);
int rpg_player_save(player_info_t *player);
int rpg_player_create_json(void);
void engine_create_text(game_global_t *global, char *text, int info[3], sfColor color);
void player_check_interaction(game_global_t *game);
int spell_speed(game_global_t *game);
int speed_spell_clock(game_global_t *game);
int destroy_map(game_global_t *game);
int interact_obj(game_global_t *game);
int obj_cooldown(game_global_t *game, double sec);
void draw_rect(game_global_t *game, int infos[4], sfColor color);
int draw_inventory(game_global_t *game);
void start_game_loop(game_global_t *game);
void pause_screen(game_global_t *game);
int event_start_screen(game_global_t *game);
int event_pause_screen(game_global_t *game);
int mob_move_passive(game_global_t *game, mob_info_t *mob, double delta_time);
int draw_mobs(game_global_t *game);
int mouse_hover(game_global_t *game, sfMouseMoveEvent event);
void show_interact_button(game_global_t *game);
#endif /* !MY_RPG_H_ */