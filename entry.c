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

int get_entry(struct Entry *dest, char *file, int filelen, char *site) {
    char *loc = (char *)memmem(file, filelen, site, strlen(site));
    if (loc == NULL) {
        return 0;
    } else {
        loc -= SITE_OFFSET;
        memcpy(&(dest -> site), loc + SITE_OFFSET, SITE_SIZE);
        memcpy(&(dest -> username), loc + USERNAME_OFFSET, USERNAME_SIZE);
        memcpy(&(dest -> password), loc + PASSWORD_OFFSET, PASSWORD_SIZE);
    }
    return 1;
}

int remove_entry(char *dest, char *file, int filelen, char *site) {
    char *loc = memmem(file, filelen, site, strlen(site));
    if (loc == NULL) {
        return 0;
    }
    loc -= SITE_OFFSET;
    int index = loc - file;
    memcpy(dest, file, index);
    memcpy(dest + index, loc + ENTRY_SIZE, (filelen - index) - ENTRY_SIZE);
    return 1;
}

void print_all_sites(char *file, int filelen) {
    int index = SITE_OFFSET;
    printf("\n");
    while (index < filelen) {
        printf("%s, ", file + index);
        index += ENTRY_SIZE;
    }
    printf("\n");
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

char *memmem(char *src, int srclen, char *match, int matchlen) {
    int i, j, m;
    for (i = 0; i <= srclen - matchlen; i += 1) {
        m = 1;
        for (j = 0; j < matchlen; j += 1) {
            if (src[i + j] != match[j]) {
                m = 0;
                break;
            }
        }
        if (m) {
            return src + i;
        }
    }
    return NULL;
}