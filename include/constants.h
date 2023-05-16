/**
 * @file constants.h
 * @author Kalinka (https://github.com/KalinkaGit)
 * @brief Constants used in the program.
 * @version 1.0.0
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CONSTANTS_H_
    #define CONSTANTS_H_

    /**
     * @brief Program exit codes.
     */
    typedef enum {
        CEXIT_SUCCESS = 0,    /**< Program ran successfully. */
        CEXIT_FAILURE = 1     /**< Program failed. */
    } exit_code_t;

    /**
     * @brief Function return codes.
     */
    typedef enum {
        CRETURN_SUCCESS = 0,   /**< Function ran successfully. */
        CRETURN_FAILURE = -1,  /**< Function failed. */
        CRETURN_NOW = 1        /**< Function ran successfully, program stop. */
    } return_code_t;

    /**
     * @brief Program options.
     */
    typedef enum {
        OPT_HELP = 1,       /**< Help option. */
        OPT_VERSION = 2,    /**< Version option. */
        OPT_SCAN = 4,       /**< Scan option. */
        OPT_DEVICE = 8,     /**< Device option. */
        OPT_TIMEOUT = 16,   /**< Timeout option. */
        OPT_DISTANCE = 32   /**< Distance option. */
    } opt_enum_t;

#endif /* !CONSTANTS_H_ */
