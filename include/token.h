#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_LET,
    TOKEN_EQ,
    TOKEN_SEMI,
    TOKEN_IDENTIFIER,
    TOKEN_UNKNOWN,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

#endif 
