#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include "token/token.h"

typedef struct {
    Token *data;
    size_t size;
    size_t capacity;
} List;


void init_list(List *list);
void free_list(List *list);
void list_append(List *list, Token value);
Token list_get(List *list, size_t index);
void list_set(List *list, size_t index, Token value);
size_t list_size(List *list);
void list_print(List *list);

#endif