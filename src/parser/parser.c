#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"
#include "list.h"
#include "token.h"


char* c_file = NULL;  

void nextToken(List *tokens, Token **cur, size_t *index) {
    if (*index + 1 < tokens->size) {
        *cur = (Token *)get_from_list(tokens, *index + 1);
        (*index)++;
    } else {
        *cur = NULL;
    }
}

void add_c_file(char *code) {
    if (!c_file) {
        c_file = (char *)malloc(1);
        c_file[0] = '\0';
    }
    size_t new_len = strlen(c_file) + strlen(code) + 1;
    c_file = (char *)realloc(c_file, new_len);
    strcat(c_file, code);
    strcat(c_file, "\n");
}

void parse(List tokens) {
    add_c_file("int main(){");
    for (size_t i = 0; i < tokens.size; i++) {
        Token *cur = (Token *)get_from_list(&tokens, i);
        if (cur->type == TOKEN_LET) {
            char *name = (char *)malloc(1);
            name[0] = '\0';

            nextToken(&tokens, &cur, &i);

            while (cur != NULL && cur->type != TOKEN_EQ) {
                size_t new_len = strlen(name) + strlen(cur->value) + 1;
                name = (char *)realloc(name, new_len);
                strcat(name, cur->value);

                nextToken(&tokens, &cur, &i);
            }

            char *data = (char *)malloc(1);
            data[0] = '\0';

            nextToken(&tokens, &cur, &i);

            while (cur != NULL && cur->type != TOKEN_SEMI) {
                size_t new_len = strlen(data) + strlen(cur->value) + 1;
                data = (char *)realloc(data, new_len);
                strcat(data, cur->value);

                nextToken(&tokens, &cur, &i);
            }

            char *code = (char *)malloc(strlen(name) + strlen(" = ") + strlen(data) + strlen(";") + 1);
            sprintf(code, "%s = %s;", name, data);
            add_c_file(code);

            free(name);
            free(data);
            free(code);
        }
    }
    add_c_file("}");
}
