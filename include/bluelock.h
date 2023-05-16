/**
 * @file bluelock.h
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Main header of the program.
 * @version 1.0.0
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BLUELOCK_H_
    #define BLUELOCK_H_

    /* LOCAL INCLUDES */
    #include "constants.h"

    typedef struct {
        char *device;
        int timeout;
        int distance;
        int options;
    } options_t;

    typedef struct {
        char **help;
        char **version;
    } messages_t;

    typedef struct {
        messages_t *messages;
        options_t *options;
    } bluelock_t;

    /**
     * @brief Execute the program.
     * 
     * @param bluelock Bluelock structure.
     * @return return_code_t Return code.
     */
    return_code_t exec_bluelock(bluelock_t *bluelock);

#endif /* !BLUELOCK_H_ */
