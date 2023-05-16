/**
 * @file handlers.h
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Handlers of the program.
 * @version 1.0.0
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HANDLERS_H_
    #define HANDLERS_H_

    /* LOCAL INCLUDES */
    #include "bluelock.h"
    #include "constants.h"

    /**
     * @brief Handle arguments of the program.
     *
     * @param argc Arguments count.
     * @param argv Arguments vector.
     * @param bluelock Bluelock structure.
     * @return int 0 if handling was successful, -1 otherwise.
     */
    return_code_t handle_args(int argc, char *argv[], bluelock_t *bluelock);

    /**
     * @brief Handle errors of the program.
     *
     * @param bluelock Bluelock structure.
     * @return int 0 if handling was successful, -1 otherwise.
     */
    return_code_t handle_errors(bluelock_t *bluelock);

#endif
