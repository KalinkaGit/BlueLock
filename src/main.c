/*
** EPITECH PROJECT, 2022
** BlueLock Main
** File description:
** BlueLock Main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

void print_help(void)
{
    printf("USAGE\n");
    printf("\t./bluelock [MAC ADDRESS]\n");
    printf("DESCRIPTION\n");
    printf("\tMAC ADDRESS\tMAC address used to lock the pc if it isn't connected\n");
    exit(0);
}

void is_valid_mac(char *mac)
{
    if (strlen(mac) != 17) {
        printf("Invalid MAC address");
        exit(84);
    }

    for (int i = 0; i < 17; i++) {
        if (i % 3 == 2) {
            if (mac[i] != ':') {
                printf("Invalid MAC address");
                exit(84);
            }
        } else {
            if ((mac[i] < '0' || mac[i] > '9')
                && (mac[i] < 'A' || mac[i] > 'F')
                && (mac[i] < 'a' || mac[i] > 'f')) {
                printf("Invalid MAC address\n");
                exit(84);
            }
        }
    }
}

int check_state(char *mac)
{
    char *command = malloc(sizeof(char) * 100);
    sprintf(command, "bluetoothctl info \"%s\"", mac);
    FILE *fp = popen(command, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Connected: yes") != NULL) {
            return (1);
        }
    }
    pclose(fp);
    return (0);
}

int main(int ac, char **argv)
{
    if (ac != 2)
        print_help();
    is_valid_mac(argv[1]);
    int connected = check_state(argv[1]);
    while (1) {
        if (connected == 0) {
            printf("Device disconnected, locking pc");
            system("xdg-screensaver lock");
            exit(0);
        }
        sleep(1);
        connected = check_state(argv[1]);
    }
    return (0);
}
