/*
** EPITECH PROJECT, 2018
** GET_NEXT_LINE.C
** File description:
** 	File used for config GNL
*/


#ifndef READ_SIZE_H_
#define READ_SIZE_H_ (10)
#endif

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define EXIT_ERROR (84)

char *get_next_line(int);
// return the next line of a file

char *fill_the_buff(int, char *);

char *get_next_line_f(int);
// return the next line of a file


char *fill_the_buff_f(int, char *);

#endif
