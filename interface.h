#include <stdio.h>

#ifndef INTERFACE_H
#define INTERFACE_H

#include "entry.h"

#define PROMPT_MODE "\nPassword Manager\n----------------\n1. Add entry\n2. Search\n3. Delete\n4. List\n5. Quit\nEnter choice [1/2/3/4/5]: "

#define PROMPT_SITE_1 "\nPassword Manager: Add entry\n---------------------------\nEnter site: "

#define PROMPT_SITE_2 "\nPassword Manager: Search for entry\n----------------------------------\nEnter site: "

#define PROMPT_SITE_3 "\nPassword Manager: Delete entry\n------------------------------\nEnter site: "

#define PROMPT_USERNAME "\nEnter username: "

#define PROMPT_PASSWORD "\nEnter password: "

#define ADD_SUCCESS "\nAdded entry successfully."

#define ENTRY_RETRIEVE "\nFound entry for site %s:\n"

#define SEARCH_FAIL "\nEntry not found\n"

#define INVALID_MODE "\nPlease enter a number 1-5\n"

char prompt_mode();
void prompt_site(char *buffer, char *prompt);
void prompt_username(char *buffer);
void prompt_password(char *buffer);
void print_entry(struct Entry *entry);
void iinvalid_mode();

void isearch_entry();
void iadd_entry();
void iremove_entry();

#endif