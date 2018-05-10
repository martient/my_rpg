/*
** EPITECH PROJECT, 2018
** rpg_save_player_default.c
** File description:
** Function that makes the default save
*/

void rpg_player_save_phase_1(int fd, char *name, int x, int y);
void rpg_player_save_phase_2(int fd, int health, int max_health,
int mana);
void rpg_player_save_phase_3(int fd, int skill_point, int inv_size,
int direction);
void rpg_player_save_phase_4(int fd, int zone, int quest_id, float xp);
void rpg_player_save_phase_5(int fd, int lvl);

void default_save(int fd)
{
	rpg_player_save_phase_1(fd, "Player", 10, 90);
	rpg_player_save_phase_2(fd, 100, 100, 0);
	rpg_player_save_phase_3(fd, 0, 1, 0);
	rpg_player_save_phase_4(fd, 1, 0, 0.0);
	rpg_player_save_phase_5(fd, 1);
}