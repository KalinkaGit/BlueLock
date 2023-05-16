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
#include "bluelock.h"
#include "constants.h"
#include "display.h"
#include "handlers.h"

return_code_t handle_errors(bluelock_t *bluelock)
{
    if (bluelock->options->options & OPT_HELP) {
        if (display_help(bluelock) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
        return (CRETURN_NOW);
    }
    if (bluelock->options->options & OPT_VERSION) {
        if (display_version(bluelock) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
        return (CRETURN_NOW);
    }
    if (bluelock->options->options & OPT_TIMEOUT) {
        if (bluelock->options->timeout <= 0) {
            if (print_error(2, 0) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            return (CRETURN_FAILURE);
        }
    }
    if (bluelock->options->options & OPT_DEVICE) {
        if (bluelock->options->device == NULL || strlen(bluelock->options->device) != 17) {
            if (print_error(3, 0) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            return (CRETURN_FAILURE);
        }
    }
    return (CRETURN_SUCCESS);
}
