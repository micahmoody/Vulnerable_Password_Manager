#include <stdio.h>
#include "entry.h"
#include "file.h"

int main() {
    int len = get_file_length();
    printf("%d", len);
    return 0;
}