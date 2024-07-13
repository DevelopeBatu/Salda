#ifndef PARSER_H
#define PARSER_H

#include "list.h"
#include "token.h"

extern char* c_file;  // c_file değişkenini burada bildirin

void nextToken(List *tokens, Token **cur, size_t *index);
void add_c_file(char *code);
void parse(List tokens);

#endif // PARSER_H
