/**
 * @file error.c
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Error printing functions
 * @version 1.0.0
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* SYSTEM INCLUDES */
#include <stdio.h>
#include <stdarg.h>

/* LOCAL INCLUDES */
#include "constants.h"

return_code_t invalid_arg(char *arg)
{
    if (printf("bluelock: invalid option -- '%s'", arg) < 0)
        return (CRETURN_FAILURE);
    if (printf("\nTry 'bluelock --help' for more information.\n") < 0)
        return (CRETURN_FAILURE);
    return (CRETURN_SUCCESS);
}

return_code_t invalid_arg_count(void)
{
    if (printf("bluelock: invalid option count") < 0)
        return (CRETURN_FAILURE);
    if (printf("\nTry 'bluelock --help' for more information.\n") < 0)
        return (CRETURN_FAILURE);
    return (CRETURN_SUCCESS);
}

return_code_t invalid_timeout(void)
{
    if (printf("bluelock: invalid timeout value") < 0)
        return (CRETURN_FAILURE);
    if (printf("\nTry 'bluelock --help' for more information.\n") < 0)
        return (CRETURN_FAILURE);
    return (CRETURN_SUCCESS);
}

return_code_t invalid_adress(void)
{
    if (printf("bluelock: invalid device address") < 0)
        return (CRETURN_FAILURE);
    if (printf("\nTry 'bluelock --help' for more information.\n") < 0)
        return (CRETURN_FAILURE);
    return (CRETURN_SUCCESS);
}

return_code_t invalid_distance(void)
{
    if (printf("bluelock: invalid distance") < 0)
        return (CRETURN_FAILURE);
    if (printf("\nTry 'bluelock --help' for more information.\n") < 0)
        return (CRETURN_FAILURE);
    return (CRETURN_SUCCESS);
}

return_code_t print_error(int error, int count, ...)
{
    va_list args;
    va_start(args, count);
    switch (error) {
        case 0: {
            if (invalid_arg(va_arg(args, char *)) == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            break;
        }
        case 1: {
            if (invalid_arg_count() == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            break;
        }
        case 2: {
            if (invalid_timeout() == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            break;
        }
        case 3: {
            if (invalid_adress() == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            break;
        }
        case 4: {
            if (invalid_distance() == CRETURN_FAILURE)
                return (CRETURN_FAILURE);
            break;
        }
        default: {
            if (printf("bluelock: unknown error") < 0)
                return (CRETURN_FAILURE);
            break;
        }
    }
    va_end(args);
    return (CRETURN_SUCCESS);
}
