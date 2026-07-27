#ifndef ENTRY_H
#define ENTRY_H

#define ENTRY_SIZE      200
#define HEADER_SIZE      10
#define SITE_OFFSET      10
#define SITE_SIZE        50
#define USERNAME_OFFSET  60
#define USERNAME_SIZE    70
#define PASSWORD_OFFSET 130
#define PASSWORD_SIZE    70

//entries are 200B long
    //bytes 0-9: header
    //10-59: site
    //60-129: username
    //130-199: password
struct Entry {
    char site[50];
    char username[70];
    char password[70];
};

void format_entry(char *buffer, struct Entry *reference);
int get_entry(struct Entry *dest, char *file, int filelen, char *site);
int remove_entry(char *dest, char *file, int filelen, char *site);
char *memmem(char *src, int srclen, char *match, int matchlen);
void print_raw_entry(char *str);

#endif