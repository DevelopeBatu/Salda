#ifndef EVAL_H
#define EVAL_H

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_UNKNOWN
} EvalType;

EvalType eval(const char *expr, double *result);

#endif // EVAL_H
