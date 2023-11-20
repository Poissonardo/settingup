/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** get_map_info.c
*/

#include <stdlib.h>
#include "../../../includes/my.h"

int get_nb_rows(char *file_content, int nb_cols)
{
    int nb_rows;
    char *first_line = malloc(sizeof(char) * (nb_cols + 1));

    if (!file_content)
        return (-1);
    for (int i = 0; file_content[i] != '\0'; i++) {
        if (file_content[i] == '\n')
            break;
        if (file_content[i] == '\0')
            return -1;
        first_line[i] = file_content[i];
    }
    nb_rows = my_getnbr(file_content);
    if (nb_rows > 0)
        return nb_rows;
    return (-1);
}

int get_nb_cols(char *file_content)
{
    int nb_cols = 0;
    int n = 0;

    if (!file_content)
        return (-1);
    for (; file_content[n] != '\0'; n++) {
        if (file_content[n] == '\n')
            break;
    }
    n++;
    for (; file_content[n] != '\0'; n++) {
        if (file_content[n] == '\n')
            break;
        if (file_content[n + 1] == '\0')
            return (-1);
        nb_cols++;
    }
    return nb_cols;
}
