/*
** EPITECH PROJECT, 2023
** setting_up.c
** File description:
** none
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_headerfiles.h"

int can_place_square(char **board, int x, int y, int size)
{
    int width = my_strlen(board[0]);
    int height = 0;
    int result = 1;
    int i;
    int j;

    while (board[height])
        height++;
    i = y;
        while (result && i < y + size) {
        j = x;
        result = (i < height);
        while (result && j < x + size) {
            result = (j < width && board[i][j] == '.');
            j++;
        }
        i++;
    }
    return result;
}

void mark_largest_square(char **board, int max_x, int max_y, int max_size)
{
    for (int i = max_y; i < max_y + max_size; i++) {
        for (int j = max_x; j < max_x + max_size; j++) {
            board[i][j] = 'x';
        }
    }
}

int find_squaresize(char **board, int x, int y, SquareContext *context)
{
    int size = 1;
    int width = my_strlen(board[0]);
    int height = 0;

    while (board[height])
        height++;
    while (can_place_square(board, x, y, size)
    && size < height - y + 1 && size < width - x + 1) {
        size++;
    }
    if (size - 1 > context->max_size) {
        context->max_size = size - 1;
        context->max_x = x;
        context->max_y = y;
    }
    return size - 1;
}

void find_largest_square(char **board, int width, int height)
{
    SquareContext context = {0, 0, 0};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            find_squaresize(board, x, y, &context);
        }
    }
    mark_largest_square(board,
    context.max_x, context.max_y, context.max_size);
}

void print_board(char **board, int height)
{
    for (int i = 0; i < height; i++) {
        my_putstr(board[i]);
        my_putchar('\n');
    }
}
