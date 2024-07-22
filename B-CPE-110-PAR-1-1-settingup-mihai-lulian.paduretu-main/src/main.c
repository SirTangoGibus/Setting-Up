/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** none
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_headerfiles.h"

static int string_to_int(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
    sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        } else {
            return -1;
        }
    }
    return result * sign;
}

char **generate_board(int width, int height, char *pattern)
{
    if (width < 0) {
        mini_printf("Error: Width cannot be negative.\n");
        return NULL;
    }
    return create_board(width, height, pattern);
}

char **create_board_with_error_handling(int argc, char *argv[])
{
    int width;
    int height;
    int pattern_length;
    char *pattern;

    if (argc != 3) {
        mini_printf("Usage: %s width pattern\n", argv[0]);
        return;
    }
    width = string_to_int(argv[1]);
    pattern = argv[2];
    pattern_length = my_strlen(pattern);
    if (pattern_length > 0) {
        height = (width > pattern_length) ? width : pattern_length;
    } else {
        height = width;
    }
    return generate_board(width, height, pattern);
}

int find_and_print_largest_square(int argc, char *argv[])
{
    char **board = create_board_with_error_handling(argc, argv);
    int width;
    int height;

    if (board == NULL) {
        mini_printf("Error: Invalid arguments or board creation failed.\n");
        return -1;
    }
    width = (argc != 3) ? 0 : string_to_int(argv[1]);
    height = (argc != 3) ? 0 : string_to_int(argv[1]);
    find_largest_square(board, width, height);
    print_board(board, height);
    for (int i = 0; i < height; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}

int main(int argc, char *argv[])
{
    char **board;
    int result;

    if (argc != 3) {
    mini_printf("Usage: %s width pattern\n", argv[0]);
    return 84;
    }
    **board = create_board_with_error_handling(argc, argv);
    if (board == NULL) {
        mini_printf("Error: Invalid arguments or board creation failed.\n");
        return 84;
    }
    result = find_and_print_largest_square(argc, argv);
    if (result == -1) {
        return 84;
    }
    return 0;
}
