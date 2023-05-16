/*
** EPITECH PROJECT, 2023
** BlueLock
** File description:
** docs
*/

/* SYSTEM INCLUDES */
#include <stdio.h>
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "bluelock.h"
#include "constants.h"
#include "display.h"

return_code_t retrieve_messages(bluelock_t *bluelock)
{
    if (!bluelock)
        return (CRETURN_FAILURE);

    bluelock->messages = malloc(sizeof(messages_t));
    if (!bluelock->messages)
        return (CRETURN_FAILURE);

    FILE *help_file = fopen("docs/help.txt", "r");
    FILE *version_file = fopen("docs/version.txt", "r");

    if (!help_file || !version_file)
        return (CRETURN_FAILURE);

    bluelock->messages->help = malloc(sizeof(char *) * 100);
    bluelock->messages->version = malloc(sizeof(char *) * 100);

    if (!bluelock->messages->help || !bluelock->messages->version)
        return (CRETURN_FAILURE);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;


    for (int i = 0; (read = getline(&line, &len, help_file)) != -1; i++) {
        bluelock->messages->help[i] = malloc(sizeof(char) * (read + 1));
        if (!bluelock->messages->help[i])
            return (CRETURN_FAILURE);
        for (int j = 0; j < read; j++)
            bluelock->messages->help[i][j] = line[j];
        bluelock->messages->help[i][read] = '\0';
    }

    for (int i = 0; (read = getline(&line, &len, version_file)) != -1; i++) {
        bluelock->messages->version[i] = malloc(sizeof(char) * (read + 1));
        if (!bluelock->messages->version[i])
            return (CRETURN_FAILURE);
        for (int j = 0; j < read; j++)
            bluelock->messages->version[i][j] = line[j];
        bluelock->messages->version[i][read] = '\0';
    }

    fclose(help_file);
    fclose(version_file);

    return (CRETURN_SUCCESS);
}

return_code_t display_version(bluelock_t *bluelock)
{
    if (!bluelock || !bluelock->messages || !bluelock->messages->version)
        return (CRETURN_FAILURE);

    char **version = bluelock->messages->version;

    for (int i = 0; version[i]; i++) {
        if (printf("%s", version[i]) < 0)
            return (CRETURN_FAILURE);
    }

    if (printf("\n") < 0)
        return (CRETURN_FAILURE);

    return (CRETURN_SUCCESS);
}

return_code_t display_help(bluelock_t *bluelock)
{
    if (!bluelock || !bluelock->messages)
        return (CRETURN_FAILURE);

    char **help = bluelock->messages->help;

    for (int i = 0; help[i]; i++) {
        if (printf("%s", help[i]) < 0)
            return (CRETURN_FAILURE);
    }

    if (printf("\n") < 0)
        return (CRETURN_FAILURE);

    return (CRETURN_SUCCESS);
}
