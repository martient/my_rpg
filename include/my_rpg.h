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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mobs_data.h"
#include "mobs.h"
#include "mobs_attack.h"
#include "player.h"
#include "keyboard.h"
#include "text.h"
#include "../extern_libs/nxjson.h"
#include "inventory.h"
#include "skill_tree.h"
#include "sound.h"
#include "global.h"
#include "items_data.h"
#include "map.h"
#include "lib.h"
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
#define PLAYER_SPEED 150
#endif

#ifndef OBJ_DISCARD_EXP
#define OBJ_DISCARD_EXP 50
#endif

#ifndef QUEST_COMPLETED
#define QUEST_COMPLETED 500
#endif

enum player_direction {
	null_direction,
	down,
	left,
	right,
	up
};

typedef int (*skills_func_t)(game_global_t *);

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
void key_event(game_global_t *game, double delta_time);
int rpg_init_global_info(object_first_t *info);
object_first_t *rpg_init_object_list(void);
int rpg_inject_object_list(object_first_t *info, const nx_json *data, int pos);
int rpg_inject_object_grass_list(object_first_t *info);
map_info_t *rpg_map_info(void);
int inventory_new_obj(game_global_t *game, char *name);
int get_item_quantity(game_global_t *game, char *item);
skills_t *init_skill_tree(void);
int rpg_mob_remove_spe(mob_first_t *first, mob_info_t *mobs);
int sky_attack(game_global_t *game);
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
void engine_create_text(game_global_t *global, char *text, int info[3],
sfColor color);
void player_check_interaction(game_global_t *game);
int spell_speed(game_global_t *game);
int speed_spell_clock(game_global_t *game);
void mobs_basic_attack(game_global_t *game);
int destroy_map(game_global_t *game);
int reset_inventory(inventory_list_t *ivnt);
void level_up(game_global_t *game);
int interact_obj(game_global_t *game);
int obj_cooldown(game_global_t *game, double sec);
void draw_rect(game_global_t *game, int infos[4], sfColor color);
void player_move(game_global_t *game, double delta_time, int direction);
int rpg_mob_remove_spe(mob_first_t *first, mob_info_t *mobs);
int find_mob(int opt, game_global_t *game);
int play_sound(game_global_t *game, char *name);
int all_touched(mob_first_t *first, player_info_t *player);
int draw_inventory(game_global_t *game);
int all_touched(mob_first_t *first, player_info_t *player);
int double_(game_global_t *game);
void start_game_loop(game_global_t *game);
void pause_screen(game_global_t *game);
void basic_init(player_info_t *player);
void saved_init(player_info_t *player, const nx_json* json);
int event_start_screen(game_global_t *game);
int event_pause_screen(game_global_t *game);
int mob_move_passive(game_global_t *game, mob_info_t *mob, double delta_time);
int draw_mobs(game_global_t *game);
int circular_(game_global_t *game);
int simple_(struct game_global_t *game);
int find_mob(int opt, game_global_t *game);
void analyse_mob(int type, mob_info_t *mob, player_info_t *player);
char *int_to_string(int number);
int inventory_get_count(game_global_t *game, char *item);
int mouse_click(game_global_t *game, sfMouseButtonEvent event);
int mouse_hover(game_global_t *game, sfMouseMoveEvent event);
int item_activat(game_global_t *game, items_data_t *item);
int init_sound(game_global_t *game);
void update_sound(game_global_t *game);
int play_sound(game_global_t *game, char *name);
int stop_all_music(game_global_t *game);
int stop_sound(game_global_t *game, char *name);
int only_play(game_global_t *game, char *name);
int destroy_sound(game_global_t *game);
void engine_exit(game_global_t *global);
int draw_quest_message(game_global_t *game);
void quest_manager(game_global_t *game);
int is_harvest_done(game_global_t *game);
int no_quest(game_global_t *game);
int harvest_draw_quest(game_global_t *game);
void quest_draw_manager(game_global_t *game);
int fallen_draw_quest(game_global_t *game);
int is_fallen_done(game_global_t *game);
int fallen_killed_monster(player_info_t *player, int reset);
void exit_game(game_global_t *game);
void draw_music_button(game_global_t *game);
void draw_sfx_button(game_global_t *game);
int check_sfx_status(game_global_t *game, int reset);
int check_music_status(game_global_t *game, int reset);
char *rpg_player_load(char *filepath);
sfVector2f screen_to_world_click(game_global_t *game, sfMouseButtonEvent event);
int upgrade_knight_attacks(game_global_t *game);
int upgrade_power(game_global_t *game);
int upgrade_inventory(game_global_t *game);
int upgrade_life(game_global_t *game);
void st_draw_health(game_global_t *game);
void st_draw_inventory(game_global_t *game);
void st_draw_strength(game_global_t *game);
void st_draw_attack(game_global_t *game);
void draw_sk_level(game_global_t *game, sfVector2f position, int level);
int draw_skill_tree(game_global_t *game);
int st_mouse_click(game_global_t *game, sfMouseButtonEvent event);
#endif /* !MY_RPG_H_ */
