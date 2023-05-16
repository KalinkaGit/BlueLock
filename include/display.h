/**
 * @file display.h
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Display functions of the program.
 * @version 1.0.0
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DISPLAY_H_
    #define DISPLAY_H_

    /* LOCAL INCLUDES */
    #include "bluelock.h"
    #include "constants.h"

    /**
     * @brief Print error message.
     *
     * @param error Error code.
     * @param count Count of arguments.
     * @param ... Arguments.
     * @return return_code_t 0 if printing was successful, -1 otherwise. 
     */
    return_code_t print_error(int error, int count, ...);

    /**
     * @brief Print help message.
     *
     * @param bluelock Bluelock structure.
     * @return return_code_t 0 if printing was successful, -1 otherwise. 
     */
    return_code_t display_help(bluelock_t *bluelock);

    /**
     * @brief Print version message.
     *
     * @param bluelock Bluelock structure.
     * @return return_code_t 0 if printing was successful, -1 otherwise. 
     */
    return_code_t display_version(bluelock_t *bluelock);

    /**
     * @brief Get the messages from the bluelock files.
     *
     * @param bluelock Bluelock structure.
     * @return return_code_t 0 if printing was successful, -1 otherwise. 
     */
    return_code_t retrieve_messages(bluelock_t *bluelock);

#endif /* !DISPLAY_H_ */
