/*
** EPITECH PROJECT, 2023
** Day09
** File description:
** my.h
*/

#pragma once

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_compute_factorial_rec(int nb);

int my_compute_power_rec(int nb, int power);

int my_is_prime(int nb);

char *my_strcpy(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strlowcase(char *str);

void for_positive(int a, int b, long c);

void for_negative(long a, int b, long c);

void for_positive_b(long nb, int arg_length, long result_holder, char *base_str);

void
for_negative_b(long nb, int arg_length, long result_holder, char *base_str);

int is_alphanum(char a);

void for_positive_err(int nb, int arg_length, long result_holder);

void for_negative_err(long nb, int arg_length, long result_holder);
