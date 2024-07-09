#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "token.h"

void init_list(List *list) {
    list->size = 0;
    list->capacity = 10;
    list->items = malloc(sizeof(void*) * list->capacity);
}

void append_to_list(List *list, void *item, size_t item_size) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->items = realloc(list->items, sizeof(void*) * list->capacity);
    }
    void *new_item = malloc(item_size);
    memcpy(new_item, item, item_size);
    list->items[list->size++] = new_item;
}

void* get_from_list(List *list, size_t index) {
    if (index < list->size) {
        return list->items[index];
    }
    return NULL;
}

void free_list(List *list) {
    for (size_t i = 0; i < list->size; i++) {
        Token *token = (Token*)list->items[i];
        if (token->value) {
            free(token->value);
        }
        free(list->items[i]);
    }
    free(list->items);
}

void print_list(const List *list) {
    printf("[");
    for (size_t i = 0; i < list->size; i++) {
        Token *token = (Token*)list->items[i];
        if (i > 0) {
            printf(", ");
        }
        printf("{ type: ");
        switch (token->type) {
            case TOKEN_INT:
                printf("INT, ");
                break;
            case TOKEN_PLUS:
                printf("PLUS, ");
                break;
            case TOKEN_EQ:
                printf("EQ, ");
                break;
            case TOKEN_LET:
                printf("LET, ");
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER, ");
                break;
            case TOKEN_UNKNOWN:
                printf("UNKNOWN, ");
                break;
            case TOKEN_EOF:
                printf("EOF, ");
                break;
            default:
                printf("UNKNOWN, ");
                break;
        }
        printf("value: '%s' }", token->value);
    }
    printf("]\n");
}
