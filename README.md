# C Password Manager

Intentionally made fairly vulnerable for future binary exploitation via pwntools

# Structure

Every entry stored in file has the following structure:

bytes 0-9: header (currently "\nNEWENTRY:")
10-59: site (50 bytes)
60-129: username (70 bytes)
130-199: password (70 bytes)

entries are stored immediately after one another with no padding

fgets reads only as many bytes as allotted for each field, so if you enter
a 70 byte site, for example, it only stored 50 of them. prevents overwriting
other fields and overflows.

# Found vulnerabilities:

(1)

get_entry calls m_memmem with strlen(site) as match length, so if the site
has length 0 (just press enter) then m_memmem matches immediately at the 
start of the buffer. so: loc -> file[0], then loc -= SITE_OFFSET points before the buffer.

eventually index = -10 is passed as size_t argument to memcpy, which at least crashes the program

(2)

m_memmem checks for matches only -- it doesn't know when it's looking for a particular site, or
which field it's supposed to be checking. so if you search for, say, "2" then it finds the first
instance of the character 2 in the file and returns its address.
then when remove_entry computes (filelen - index) - ENTRY_SIZE the result is a negative integer, which is cast to a very large unsigned one when passed as size_t to memcpy,
causing the program to try and copy an enormous amount of memory into a buffer, overwriting other things
on the stack.