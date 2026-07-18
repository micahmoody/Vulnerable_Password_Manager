#include <stdio.h>
#include "entry.h"
#include "file.h"

int main() {

    struct Entry entry = {"https://www.test.com", "username@fakeemail.com", "abracadabra"};
    char formatted_result_buffer[300];
    format_entry(formatted_result_buffer, &entry);
    push_entry(formatted_result_buffer);

    char buffer[300];
    copy_file(buffer);
    struct Entry retrieved;
    get_entry(&retrieved, buffer, "https://www.test.com");

    char frb2[300];
    format_entry(frb2, &retrieved);

    print_entry(frb2);

    return 0;
}