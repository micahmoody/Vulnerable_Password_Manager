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
    prompt_site(entry_buffer.site, PROMPT_SITE_1);
    prompt_username(entry_buffer.username);
    prompt_password(entry_buffer.password);
    format_entry(formatted_result, &entry_buffer);
    push_entry(formatted_result);
    printf(ADD_SUCCESS);
}

void isearch_entry() {
    int len = get_file_length();
    char site[SITE_SIZE + 1];
    char file_buffer[len + 1];
    struct Entry entry;
    prompt_site(site, PROMPT_SITE_2);
    copy_file(file_buffer);
    int found = get_entry(&entry, file_buffer, len, site);
    if (found) {
        print_entry(&entry);
    } else {
        printf(SEARCH_FAIL);
    }
}

void iremove_entry() {
    int len = get_file_length();
    char file_buffer[len + 1];
    char file_buffer_removed[len - ENTRY_SIZE];
    char site[SITE_SIZE];
    prompt_site(site, PROMPT_SITE_3);
    copy_file(file_buffer);
    remove_entry(file_buffer_removed, file_buffer, len, site);
    overwrite(file_buffer_removed, len + 1 - ENTRY_SIZE);
}

void ilist_entries() {
    int len = get_file_length();
    char file_buffer[len + 1];
    copy_file(file_buffer);
    print_all_sites(file_buffer, len);
}

void iinvalid_mode() {
    printf(INVALID_MODE);
}

char prompt_mode() {
    printf(PROMPT_MODE);
    char c = getchar();
    clear_input_buffer();
    return c;
}

void prompt_site(char *buffer, char *prompt) {
    printf(prompt);
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