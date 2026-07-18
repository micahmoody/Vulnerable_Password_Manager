#include <stdio.h>
#include <string.h>
#include "entry.h"

void format_entry(char *buffer, struct Entry *reference) {

    strcpy(buffer, "\nNEWENTRY:");
    memcpy(buffer + 10, &(reference -> site), 50);
    memcpy(buffer + 60, &(reference -> username), 70);
    memcpy(buffer + 130, &(reference -> password), 70);
    //entries are 200B long
    //bytes 0-9: header
    //10-59: site
    //60-129: username
    //130-199: password
}

void get_entry(struct Entry *dest, char *file, char *site) {
    char *loc = strstr(file, site);
    memcpy(&(dest -> site), loc, 50);
    memcpy(&(dest -> username), loc + 50, 70);
    memcpy(&(dest -> password), loc + 130, 70);
}

void print_entry(char *str) {
    int i;
    for (i = 0; i < 200; i += 1) {
        if (str[i] == '\0') {
            printf("_");
            continue;
        }
        printf("%c", str[i]);
    }
}