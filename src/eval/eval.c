#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "eval.h"

// Function to skip whitespace
static const char* skip_whitespace(const char *str) {
    while (isspace(*str)) {
        str++;
    }
    return str;
}

// Parse a number (integer or float)
static const char* parse_number(const char *str, double *value) {
    char *endptr;
    *value = strtod(str, &endptr);
    return endptr;
}

EvalType eval(const char *expr, double *result) {
    double current_value = 0;
    double total = 0;
    char op = '+';
    EvalType type = TYPE_UNKNOWN;
    expr = skip_whitespace(expr);

    while (*expr != '\0') {
        if (isdigit(*expr) || *expr == '.') {
            expr = parse_number(expr, &current_value);
            if (type == TYPE_UNKNOWN) {
                type = (strchr(expr, '.') != NULL) ? TYPE_FLOAT : TYPE_INT;
            }
            if (op == '+') {
                total += current_value;
            } else if (op == '-') {
                total -= current_value;
            }
        } else if (*expr == '+' || *expr == '-') {
            op = *expr;
            expr++;
        } else {
            return TYPE_UNKNOWN;  // Invalid character
        }
        expr = skip_whitespace(expr);
    }

    *result = total;
    return type;
}
