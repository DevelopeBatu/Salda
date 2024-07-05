#include "SaldaString.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Length of the string
size_t len(const char *str) {
    return strlen(str);
}


int starts_with(const char *str, const char *prefix) {
    size_t len_prefix = strlen(prefix);
    size_t len_str = strlen(str);
    return len_str < len_prefix ? 0 : strncmp(str, prefix, len_prefix) == 0;
}

// Check if string ends with a given suffix
int ends_with(const char *str, const char *suffix) {
    size_t len_suffix = strlen(suffix);
    size_t len_str = strlen(str);
    return len_str < len_suffix ? 0 : strcmp(str + len_str - len_suffix, suffix) == 0;
}

// Convert string to uppercase
char *to_upper(char *str) {
    for (char *p = str; *p; ++p) {
        *p = toupper((unsigned char) *p);
    }
    return str;
}

// Convert string to lowercase
char *to_lower(char *str) {
    for (char *p = str; *p; ++p) {
        *p = tolower((unsigned char) *p);
    }
    return str;
}

// Trim whitespace from both ends of the string
char *trim(char *str) {
    return ltrim(rtrim(str));
}

// Trim whitespace from the left end of the string
char *ltrim(char *str) {
    while (isspace((unsigned char) *str)) str++;
    return str;
}

// Trim whitespace from the right end of the string
char *rtrim(char *str) {
    char *end = str + strlen(str);
    while (end > str && isspace((unsigned char) *(--end))) {
        *end = '\0';
    }
    return str;
}
