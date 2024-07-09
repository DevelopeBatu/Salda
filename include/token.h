#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_UNKNOWN,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

#endif // TOKEN_H
