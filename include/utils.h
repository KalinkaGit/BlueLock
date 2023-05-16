/**
 * @file utils.h
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Utility functions of the program.
 * @version 1.0.0
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UTILS_H_

    /* LOCAL INCLUDES */
    #include "bluelock.h"
    #include "constants.h"

    /**
     * @brief Scan for bluetooth devices.
     * 
     * @param bluelock Pointer to the bluelock_t struct.
     * @return return_code_t Return code.
     */
    return_code_t scan_devices(bluelock_t *bluelock);

#endif