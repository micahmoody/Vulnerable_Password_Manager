#include <stdio.h>
#include <string.h>
#include "entry.h"

struct Entry {
    char site[50];
    char username[50];
    char password[50];
};

void format_entry(char *buffer, struct Entry *reference) {

    strcpy(buffer, "\nNEWENTRY:\nSITE____:");
    strcpy(buffer + 20, reference -> site);
    strcpy(buffer + 70, "USERNAME_:");
    strcpy(buffer + 80, reference -> username);
    strcpy(buffer + 130, "PASSWORD_:");
    strcpy(buffer + 140, reference -> password);
    strcpy(buffer + 190, "END-ENTRY_");
    //entries are 200B long. site at byte 20, username at byte 70, password byte 130
}

void get_entry(char *file, struct Entry *entry, char *site) {
    char *loc = strstr(file, sprintf("SITE____:%s", site));
}
