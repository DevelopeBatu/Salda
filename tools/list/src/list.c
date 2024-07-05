#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

// Initialize the list
void init_list(List *list) {
    list->data = (Token *)malloc(INITIAL_CAPACITY * sizeof(Token));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

// Free the list
void free_list(List *list) {
    for (size_t i = 0; i < list->size; ++i) {
        free(list->data[i].type);
        free(list->data[i].value);
    }
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

// Append an item to the list
void list_append(List *list, Token value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (Token *)realloc(list->data, list->capacity * sizeof(Token));
    }
    list->data[list->size++] = value;
}

// Get an item from the list
Token list_get(List *list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return list->data[index];
}

// Set an item in the list
void list_set(List *list, size_t index, Token value) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    list->data[index] = value;
}

// Get the size of the list
size_t list_size(List *list) {
    return list->size;
}

// Print the list
void list_print(List *list) {
    for (size_t i = 0; i < list->size; ++i) {
        print_token(&list->data[i]);
        printf("\n");
    }
}
