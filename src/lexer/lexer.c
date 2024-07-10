#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
#include "list.h"
#include "token.h"

static Token create_token(TokenType type, const char *value) {
    Token token;
    token.type = type;
    token.value = strdup(value);
    return token;
}

static void add_token(List *token_list, TokenType type, const char *start, size_t length) {
    char *value = (char*)malloc(length + 1);
    strncpy(value, start, length);
    value[length] = '\0';
    Token token = create_token(type, value);
    append_to_list(token_list, &token, sizeof(Token));
    free(value);
}

void tokenize_file(const char *filename, List *token_list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            continue;
        } else if (ch == '+') {
            add_token(token_list, TOKEN_PLUS, &ch, 1);
        } else if (ch == '=') {
            add_token(token_list, TOKEN_EQ, &ch, 1);
        } else if (ch == ';') {
            add_token(token_list, TOKEN_SEMI, &ch, 1);
        }
        else if (isdigit(ch)) {
            char buffer[64];
            size_t length = 0;
            do {
                buffer[length++] = ch;
                ch = fgetc(file);
            } while (isdigit(ch));
            buffer[length] = '\0';
            ungetc(ch, file);
            add_token(token_list, TOKEN_INT, buffer, length);
        } else if (isalpha(ch)) {
            char buffer[64];
            size_t length = 0;
            do {
                buffer[length++] = ch;
                ch = fgetc(file);
            } while (isalpha(ch));
            buffer[length] = '\0';
            ungetc(ch, file);
            if (strcmp(buffer, "let") == 0) {
                add_token(token_list, TOKEN_LET, buffer, length);
            } else {
                add_token(token_list, TOKEN_IDENTIFIER, buffer, length);
            }
        } else {
            add_token(token_list, TOKEN_UNKNOWN, &ch, 1);
        }
    }

    Token eof_token = create_token(TOKEN_EOF, "");
    append_to_list(token_list, &eof_token, sizeof(Token));

    fclose(file);
}
