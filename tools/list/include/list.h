#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct {
    void **items;
    size_t size;
    size_t capacity;
} List;

void init_list(List *list);
void append_to_list(List *list, void *item, size_t item_size);
void* get_from_list(List *list, size_t index);
void free_list(List *list);
void print_list(const List *list);

#endif // LIST_H
