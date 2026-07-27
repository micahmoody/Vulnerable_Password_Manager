#include <stdio.h>
#include <string.h>
#include "entry.h"

void format_entry(char *buffer, struct Entry *reference) {
    memset(buffer, 0, ENTRY_SIZE);
    strcpy(buffer, "\nNEWENTRY:");
    memcpy(buffer + SITE_OFFSET, &(reference -> site), SITE_SIZE);
    memcpy(buffer + USERNAME_OFFSET, &(reference -> username), USERNAME_SIZE);
    memcpy(buffer + PASSWORD_OFFSET, &(reference -> password), PASSWORD_SIZE);
}

int get_entry(struct Entry *dest, char *file, char *site) {
    char *loc = strstr(file, site);
    if (loc == NULL) {
        return 0;
    } else {
        loc -= SITE_OFFSET;
        memcpy(&(dest -> site), loc, SITE_SIZE);
        memcpy(&(dest -> username), loc + USERNAME_OFFSET, USERNAME_SIZE);
        memcpy(&(dest -> password), loc + PASSWORD_OFFSET, PASSWORD_SIZE);
    }
    return 1;
}

void print_raw_entry(char *str) {
    int i;
    for (i = 0; i < ENTRY_SIZE; i += 1) {
        if (str[i] == '\0') {
            printf("_");
            continue;
        }
        printf("%c", str[i]);
    }
}