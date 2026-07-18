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
    //if file is empty, return 0. otherwise, account for \0 in string
    return (count - 1) < 0 ? 0 : count - 1;
}