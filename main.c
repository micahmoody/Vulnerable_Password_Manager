#include <stdio.h>
#include "entry.h"
#include "file.h"
#include "interface.h"

void ui() {

    char mode = prompt_mode();

    switch (mode) {
        case '1':
            iadd_entry();
            ui();
            break;
        case '2':
            isearch_entry();
            ui();
            break;
        case '3':
            iremove_entry();
            ui();
            break;
        case '4':
            ilist_entries();
            ui();
            break;
        case '5':
            return;
        default: 
            iinvalid_mode();
            ui();
            break;
    }

}

int main() {
    ui();
    return 0;
}

