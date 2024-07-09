#ifndef LEXER_H
#define LEXER_H

#include "list.h"
#include "token.h"

void tokenize_file(const char *filename, List *token_list);

#endif // LEXER_H
