/*
** EPITECH PROJECT, 2023
** setting_upboard.c
** File description:
** none
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_headerfiles.h"

char **create_board(int width, int height, char *pattern)
{
    char **board = (char **)malloc(sizeof(char *) * height);
    int pattern_length = my_strlen(pattern);
    int patternIndex = 0;

    for (int i = 0; i < height; i++) {
        board[i] = (char *)malloc(sizeof(char) * (width + 1));
        for (int j = 0; j < width; j++) {
            board[i][j] = pattern[patternIndex];
            patternIndex = (patternIndex + 1) % pattern_length;
        }
        board[i][width] = '\0';
    }
    return board;
}
