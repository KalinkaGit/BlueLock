/*
** EPITECH PROJECT, 2023
** BlueLock
** File description:
** bluelock
*/

/* SYSTEM INCLUDES */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>

/* LOCAL INCLUDES */
#include "bluelock.h"
#include "constants.h"
#include "utils.h"

static int connect_to_device_by_mac(bluelock_t *bluelock)
{
    int socket_fd;
    struct sockaddr_rc address = {0};

    if (!bluelock || !bluelock->options)
        return (CRETURN_FAILURE);

    socket_fd = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    address.rc_family = AF_BLUETOOTH;
    address.rc_channel = (uint8_t) 1;
    str2ba(bluelock->options->device, &address.rc_bdaddr);

    if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect");
        return (CRETURN_FAILURE);
    }

    printf("Connected to device!\n");

    return (socket_fd);
}

static int get_rssi(char *mac)
{
    int rssi = 0;

    char *command = malloc(sizeof(char) * 100);

    sprintf(command, "hcitool rssi %s", mac);
    FILE *fp = popen(command, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'R') {
            rssi = atoi(line + 19);
        }
    }

    pclose(fp);

    free(command);

    return (rssi);
}

static void lock_computer(void)
{
    system("xdg-screensaver lock");
}

return_code_t connect_device(bluelock_t *bluelock)
{
    int socket_fd = -1;

    if (!bluelock || !bluelock->options)
        return CRETURN_FAILURE;

    printf("Connecting to device...\n");

    socket_fd = connect_to_device_by_mac(bluelock);
    if (socket_fd == -1) {
        printf("Connexion impossible, veuillez vérifier votre connexion Bluetooth!\n");
        return CRETURN_FAILURE;
    }

    while (1) {
        int rssi = get_rssi(bluelock->options->device);

        if (rssi < bluelock->options->distance) {
            lock_computer();
        }

        sleep(1);
    }

    close(socket_fd);

    return CRETURN_SUCCESS;
}


return_code_t exec_bluelock(bluelock_t *bluelock)
{
    if (!bluelock || !bluelock->options)
        return (CRETURN_FAILURE);

    if (bluelock->options->options & OPT_SCAN)
        return (scan_devices(bluelock));

    if (bluelock->options->options & OPT_DEVICE)
        return (connect_device(bluelock));

    return (CRETURN_SUCCESS);
}
