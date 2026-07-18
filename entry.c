#include <stdio.h>
#include <string.h>
#include "entry.h"

void format_entry(char *buffer, struct Entry *reference) {
    strcpy(buffer, "\nNEWENTRY:");
    memcpy(buffer + SITE_OFFSET, &(reference -> site), SITE_SIZE);
    memcpy(buffer + USERNAME_OFFSET, &(reference -> username), USERNAME_SIZE);
    memcpy(buffer + PASSWORD_OFFSET, &(reference -> password), PASSWORD_SIZE);
}

void get_entry(struct Entry *dest, char *file, char *site) {
    char *loc = strstr(file, site) - SITE_OFFSET;
    if (loc == NULL) {
        printf("entry with site %s not found, no action taken", site);
    } else {
        memcpy(&(dest -> site), loc, SITE_SIZE);
        memcpy(&(dest -> username), loc + USERNAME_OFFSET, USERNAME_SIZE);
        memcpy(&(dest -> password), loc + PASSWORD_OFFSET, PASSWORD_SIZE);
    }
}

void print_entry(char *str) {
    int i;
    for (i = 0; i < ENTRY_SIZE; i += 1) {
        if (str[i] == '\0') {
            printf("_");
            continue;
        }
        printf("%c", str[i]);
    }
}