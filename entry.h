#ifndef ENTRY_H
#define ENTRY_H

struct Entry {
    char site[50];
    char username[70];
    char password[70];
};

void format_entry(char *buffer, struct Entry *reference);
void get_entry(struct Entry *dest, char *file, char *site);
void print_entry(char *str);

#endif