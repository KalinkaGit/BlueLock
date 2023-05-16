/**
 * @file main.c
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Main file of the program
 * @version 1.0.0
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* SYSTEM INCLUDES */
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "bluelock.h"
#include "constants.h"
#include "handlers.h"
#include "display.h"

int main(int argc, char *argv[])
{
    bluelock_t *bluelock = malloc(sizeof(bluelock_t));
    if (!bluelock)
        return (CEXIT_FAILURE);

    if (handle_args(argc, argv, bluelock) == CRETURN_FAILURE)
        return (CEXIT_FAILURE);

    if (retrieve_messages(bluelock) == CRETURN_FAILURE)
        return (CEXIT_FAILURE);

    return_code_t ret = handle_errors(bluelock);
    if (ret == CRETURN_FAILURE)
        return (CEXIT_FAILURE);
    if (ret == CRETURN_NOW)
        return (CEXIT_SUCCESS);

    exec_bluelock(bluelock);

    return (CEXIT_SUCCESS);
}
