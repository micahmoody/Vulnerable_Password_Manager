#include <stdio.h>
#include "interface.h"
#include "entry.h"
#include "file.h"

void clear_input_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

void iadd_entry() {
    struct Entry entry_buffer;
    char formatted_result[ENTRY_SIZE];
    prompt_site(entry_buffer.site);
    prompt_username(entry_buffer.username);
    prompt_password(entry_buffer.password);
    format_entry(formatted_result, &entry_buffer);
    push_entry(formatted_result);
    printf(ADD_SUCCESS);
}

char prompt_mode() {
    printf(PROMPT_MODE);
    char c = getchar();
    clear_input_buffer();
    return c;
}

void prompt_site(char *buffer) {
    printf(PROMPT_SITE);
    fgets(buffer, SITE_SIZE, stdin);
}

void prompt_username(char *buffer) {
    printf(PROMPT_USERNAME);
    fgets(buffer, USERNAME_SIZE, stdin);
}

void prompt_password(char *buffer) {
    printf(PROMPT_PASSWORD);
    fgets(buffer, PASSWORD_SIZE, stdin);
}