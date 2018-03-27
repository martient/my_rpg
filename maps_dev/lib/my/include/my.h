/*
** EPITECH PROJECT, 2017
** MY
** File description:
** This is my lib
*/

#include "get_next_line.h"
#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

int my_printf_displayer_str (int nb, char str, char str_bis, char str_more);
void my_printf (char *format, ...);
void printf_flag_b (int value);
void printf_flag_c (char tmp);
void disp_stdarg (char *s, ...);
void printf_flag_i (int value);
void printf_flag_d (int value);
void printf_flag_o (unsigned int value);
void printf_flag_p (unsigned int value);
void printf_flag_s (char *str);
void printf_flag_x (unsigned int value);
void printf_flag_X (unsigned int value);
int sum_stdarg (int i, int nb, ...);

void select_printf_end (char str, char str_bis, va_list list);
void select_printf_bis (char str, char str_bis, va_list list);
void select_printf (char str, char str_bis, va_list list);

void my_swap(int *a, int *b);

char *my_strupcase(char *str);

int check_occurence(char const *str, char const *to_find, int index);
char *my_strstr(char const*str, char const *to_find);

char *my_strncpy(char *dest, char const *src, int n);
char *my_strncpy_last(char *dest, char const *src, int last, int n);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncat(char *dest, char const *src, int nb);
char *my_alloc_gtn(char *dest, char const *src, int lenght, int *pos);

char *my_strlowcase(char *str);

int my_strlen(char const *str);
int my_strlen_double(char const **str);

char *my_strcpy(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcat(char *dest, char const *src);
char *my_strcat_malloc(char *dest, char const *src);

char *my_strcapitalize(char *str);

void write(int, char *add, int);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *array, int size);
void my_sort_int_array_switch(int i, int j, int *array);
void display_digits(char *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_revstr(char *str);

void my_putstr(char const *str);
void my_putstr_error(char const *str);
void my_putstr_n (char const *str);
void my_putchar(char c);

void my_put_nbr(int nb);

int my_put_nbr_base_min (unsigned int number, char *str);
int my_put_nbr_base_maj (unsigned int number, char *str);
int my_put_nbr_base_octale (unsigned int number, char *str);
int my_put_nbr_base_binaire (unsigned int number, char *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_getnbr(char const* str);
int my_find_prime_sup(int nb);
int my_compute_square_root(int nb);
int my_compute_power_rec(int nb, int p);

#endif
