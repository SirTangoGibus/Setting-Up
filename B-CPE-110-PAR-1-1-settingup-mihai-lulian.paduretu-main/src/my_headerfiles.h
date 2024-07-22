/*
** EPITECH PROJECT, 2023
** headerfiles.h
** File description:
** none
*/

#ifndef HEADERFILES_H
    #define HEADERFILES_H
    #include <stdarg.h>
typedef struct {
    int max_size;
    int max_x;
    int max_y;
} SquareContext;
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
char *my_strcpy(char *dest, char const *src);
int main(int argc, char *argv[]);
int my_strcmp(char const *s1, char const *s2);
int mini_printf(const char *format, ...);
int switch_function(va_list ap, char *format);
char **create_board(int width, int height, char *pattern);
int can_place_square(char **board, int x, int y, int size);
void mark_largest_square(char **board, int max_x, int max_y, int max_size);
int find_squaresize(char **board, int x, int y, SquareContext *context);
void find_largest_square(char **board, int width, int height);
void print_board(char **board, int height);
char **create_board_with_error_handling(int argc, char *argv[]);
int find_and_print_largest_square(int argc, char *argv[]);
#endif
