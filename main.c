#include <stdio.h>
#include "entry.h"
#include "file.h"
#include "interface.h"

int main() {
    ui();
    return 0;
}

void ui() {

    char mode = prompt_mode();

    switch (mode) {
        case '1':
            iadd_entry();
            ui();
        case '2':
            isearch_entry();
            ui();
        case '5':
            return;
        default: 
            iinvalid_mode();
            ui();
    }

}