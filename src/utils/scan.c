/*
** EPITECH PROJECT, 2023
** BlueLock
** File description:
** scan
*/

/* SYSTEM INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

/* LOCAL INCLUDES */
#include "bluelock.h"
#include "constants.h"

return_code_t scan_devices(bluelock_t *bluelock)
{
    if (!bluelock)
        return (CRETURN_FAILURE);

    printf("Scanning for devices...\n");

    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    int count = 0;
    char addr[19] = {0};
    char name[248] = {0};

    dev_id = hci_get_route(NULL);
    sock = hci_open_dev(dev_id);
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        return (CRETURN_FAILURE);
    }

    len = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info *)malloc(max_rsp * sizeof(inquiry_info));

    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if (num_rsp < 0)
        perror("hci_inquiry");

    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name),
            name, 0) < 0)
            strcpy(name, "[unknown]");
        printf("%s  %s\n", addr, name);
        count++;
    }

    if (count == 0)
        printf("No devices found.\n");

    free(ii);
    close(sock);

    return (CRETURN_SUCCESS);
}
