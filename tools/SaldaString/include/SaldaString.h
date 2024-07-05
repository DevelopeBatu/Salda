#ifndef SALDA_STRING_H
#define SALDA_STRING_H

#include <stddef.h>

size_t len(const char *str);
int starts_with(const char *str, const char *prefix);
int ends_with(const char *str, const char *suffix);
char *to_upper(char *str);
char *to_lower(char *str);
char *trim(char *str);
char *ltrim(char *str);
char *rtrim(char *str);

#endif // SALDA_STRING_H
