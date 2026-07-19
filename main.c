#include <stdio.h>
#include "entry.h"
#include "file.h"
#include "interface.h"

int main() {

    char mode = prompt_mode();

    if (mode == '1') {
        iadd_entry();
    }

    return 0;
}