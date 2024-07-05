#include "token/token.h"
#include <stdio.h>

void print_token(void *data) {
    Token *token = (Token *)data;
    printf("Type: %s, Value: %s", token->type, token->value);
}
