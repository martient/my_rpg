/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** Header file for the str lib
*/

#ifndef LIB_H_
	#define LIB_H_

#include <stdlib.h>

ssize_t write(int fd, const void *buf, size_t count);
int my_put_nbr(int nb);
int rpg_file_put_nbr(int fd, int nb);
int my_putstr(char *str);
int my_strcmp(char *str, char *str2);
char *my_strdup(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *str, char *str2);
int my_put_float(float nb);
#endif /* !LIB_H_ */
