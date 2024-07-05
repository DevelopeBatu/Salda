#ifndef TOKEN_H
#define TOKEN_H

typedef struct {
    char *type;
    char *value;
} Token;

void print_token(void *data);

#endif // TOKEN_H
