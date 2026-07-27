#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "entry.h"
#include "file.h"

void clear_input_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

void iadd_entry() {
    struct Entry entry_buffer;
    char formatted_result[ENTRY_SIZE + 1];
    prompt_site_1(entry_buffer.site);
    prompt_username(entry_buffer.username);
    prompt_password(entry_buffer.password);
    format_entry(formatted_result, &entry_buffer);
    push_entry(formatted_result);
    printf(ADD_SUCCESS);
}

void isearch_entry() {
    int len = get_file_length();
    char site[SITE_SIZE + 1];
    char file_buffer[len];
    struct Entry entry;
    prompt_site_2(site);
    copy_file(file_buffer);
    int found = get_entry(&entry, file_buffer, site);
    if (found) {
        print_entry(&entry);
    } else {
        printf(SEARCH_FAIL);
    }
}

char prompt_mode() {
    printf(PROMPT_MODE);
    char c = getchar();
    clear_input_buffer();
    return c;
}

void prompt_site_1(char *buffer) {
    printf(PROMPT_SITE_1);
    fgets(buffer, SITE_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void prompt_site_2(char *buffer) {
    printf(PROMPT_SITE_2);
    fgets(buffer, SITE_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void prompt_username(char *buffer) {
    printf(PROMPT_USERNAME);
    fgets(buffer, USERNAME_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void prompt_password(char *buffer) {
    printf(PROMPT_PASSWORD);
    fgets(buffer, PASSWORD_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void print_entry(struct Entry *entry) {
    printf(ENTRY_RETRIEVE, entry -> site);
    printf("Username: %s\n", entry -> username);
    printf("Password: %s\n\n", entry -> password);
}