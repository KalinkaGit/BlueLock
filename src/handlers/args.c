/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** Arguments
*/

/* SYSTEM INCLUDES */
#include <stdlib.h>
#include <string.h>

/* LOCAL INCLUDES */
#include "constants.h"
#include "handlers.h"
#include "display.h"
#include "bluelock.h"

return_code_t get_option(char *argv[], int *index, bluelock_t *bluelock)
{
    if (strcmp(argv[*index], "-h") == 0 || strcmp(argv[*index], "--help") == 0) {
        bluelock->options->options |= OPT_HELP;
        return (CRETURN_SUCCESS);
    }
    if (strcmp(argv[*index], "-v") == 0 || strcmp(argv[*index], "--version") == 0) {
        bluelock->options->options |= OPT_VERSION;
        return (CRETURN_SUCCESS);
    }
    if (strcmp(argv[*index], "-d") == 0) {
        bluelock->options->options |= OPT_DEVICE;
        if (!argv[*index + 1]) {
            if (print_error(1, 0) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            return (CRETURN_SUCCESS);
        }
        *index += 1;
        if (!bluelock->options->device)
            bluelock->options->device = malloc(sizeof(char) * strlen(argv[*index]) + 1);
        if (!bluelock->options->device)
            return (CRETURN_FAILURE);
        strcat(bluelock->options->device, argv[*index]);
        return (CRETURN_SUCCESS);
    }
    if (strncmp(argv[*index], "--device=", 9) == 0) {
        bluelock->options->options |= OPT_DEVICE;
        if (!bluelock->options->device)
            bluelock->options->device = malloc(sizeof(char) * strlen(argv[*index] + 9) + 1);
        if (!bluelock->options->device)
            return (CRETURN_FAILURE);
        strcat(bluelock->options->device, argv[*index] + 9);
        return (CRETURN_SUCCESS);
    }
    if (strcmp(argv[*index], "-t") == 0) {
        bluelock->options->options |= OPT_TIMEOUT;
        if (!argv[*index + 1]) {
            if (print_error(1, 0) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            return (CRETURN_SUCCESS);
        }
        bluelock->options->timeout = atoi(argv[*index + 1]);
        *index += 1;
        return (CRETURN_SUCCESS);
    }
    if (strncmp(argv[*index], "--timeout=", 10) == 0) {
        bluelock->options->options |= OPT_TIMEOUT;
        bluelock->options->timeout = atoi(argv[*index] + 10);
        return (CRETURN_SUCCESS);
    }
    if (strcmp(argv[*index], "-s") == 0 || strcmp(argv[*index], "--scan") == 0) {
        bluelock->options->options |= OPT_SCAN;
        return (CRETURN_SUCCESS);
    }
    if (strcmp(argv[*index], "-D") == 0) {
        bluelock->options->options |= OPT_DISTANCE;
        if (!argv[*index + 1]) {
            if (print_error(1, 0) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            return (CRETURN_SUCCESS);
        }
        bluelock->options->distance = atoi(argv[*index + 1]);
        *index += 1;
        return (CRETURN_SUCCESS);
    }
    if (strncmp(argv[*index], "--distance=", 11) == 0) {
        bluelock->options->options |= OPT_DISTANCE;
        bluelock->options->distance = atoi(argv[*index] + 11);
        return (CRETURN_SUCCESS);
    }
    return (CRETURN_NOW);
}

return_code_t handle_args(int argc, char *argv[], bluelock_t *bluelock)
{
    if (argc < 2)
        return (CRETURN_FAILURE);

    bluelock->options = malloc(sizeof(options_t));
    if (!bluelock->options)
        return (CRETURN_FAILURE);

    for (int i = 1; i < argc; i++) {
        if (get_option(argv, &i, bluelock) == CRETURN_NOW) {
            if (print_error(0, 1, argv[i]) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            return (CRETURN_SUCCESS);
        }
    }

    return (CRETURN_SUCCESS);
}
