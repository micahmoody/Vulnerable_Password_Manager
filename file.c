#include <stdio.h>
#include "file.h"
#include "entry.h"

int get_file_length() {
    int c, count = 0;
    FILE *fp = fopen("entries.txt", "r");
    while ((c = fgetc(fp)) != EOF) {
        count += 1;
    }
    fclose(fp);
    return count;
}

void copy_file(char *buffer) {
    int c, i = 0;
    FILE *fp = fopen("entries.txt", "r");
    while((c = fgetc(fp)) != EOF) {
        buffer[i] = c;
        i += 1;
    }
    buffer[i] = '\0';
    fclose(fp);
}

void push_entry(char *str) {
    FILE *fp = fopen("entries.txt", "a");
    fwrite(str, ENTRY_SIZE, 1, fp);
    fclose(fp);
}