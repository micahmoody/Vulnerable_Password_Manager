#include <stdio.h>
#ifndef INTERFACE_H
#define INTERFACE_H

#define PROMPT_MODE "\nPassword Manager\n----------------\n1. Add entry\n2. Search\n 3. Delete\n4. List\n5. Quit\nEnter choice [1/2/3/4/5]:"

#define PROMPT_SITE "\nPassword Manager: Add entry\n---------------------------\nEnter site:"

#define PROMPT_USERNAME "\nEnter username:"

#define PROMPT_PASSWORD "\nEnter password:"

#define ADD_SUCCESS "\nAdded entry successfully."

char prompt_mode();
void prompt_site(char *buffer);
void prompt_username(char *buffer);
void prompt_password(char *buffer);

void iadd_entry();

#endif