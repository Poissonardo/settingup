/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** map_from_file.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../../includes/my.h"
#include "../../../includes/internal_functions.h"

char *file_content_to_map(char *file_content, int nb_rows, int nb_cols)
{
    char *map;
    int i = 0;

    while (file_content[i] != '\n' && file_content[i] != '\0') {
        i++;
    }
    i++;
    map = my_strdup(&file_content[i]);
    free(file_content);
    if (!is_map_valid(map, nb_rows, nb_cols))
        return NULL;
    return map;
}

char *map_from_file(char *file_path, int *nb_cols, int *nb_rows)
{
    char *file_content = open_map_file(file_path);

    if (!file_content) {
        return NULL;
    }
    *nb_cols = get_nb_cols(file_content);
    *nb_rows = get_nb_rows(file_content, *nb_cols);
    if (*nb_cols == (-1) || *nb_rows == (-1)) {
        my_puterr(
            "setting_up : failed reading file, incorrect number on line 1\n");
        return NULL;
    }
    return file_content_to_map(file_content, *nb_rows, *nb_cols);
}
