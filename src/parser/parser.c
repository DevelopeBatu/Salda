#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"
#include "list.h"
#include "token.h"
#include "eval.h"

char* c_file = NULL; // Global c_file değişkeni

void nextToken(List *tokens, Token **cur, size_t *index) {
    if (*index + 1 < tokens->size) {
        *cur = (Token *)get_from_list(tokens, *index + 1);
        (*index)++;
    } else {
        *cur = NULL;
    }
}

void parse(List tokens) {
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

            double result;
            EvalType type = eval(data, &result);
            
            switch (type) {
                case TYPE_INT: {
                    if (!c_file) {
                        c_file = (char *)malloc(1); // Başlangıç için bellek ayır
                        c_file[0] = '\0';
                    }
                    size_t new_len = strlen(c_file) + strlen("int ") + strlen(name) + strlen(" = ") + strlen(data) + strlen(";\n") + 1;
                    c_file = (char *)realloc(c_file, new_len);
                    strcat(c_file, "int ");
                    strcat(c_file, name);
                    strcat(c_file, " = ");
                    strcat(c_file, data);
                    strcat(c_file, ";\n");
                    break;
                }
                default:
                    printf("The expression type is unknown or invalid.\n");
                    break;
            }

            free(name);
            free(data);
        }
    }
}
