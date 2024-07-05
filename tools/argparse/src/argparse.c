#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"

void init_parser(ArgumentParser *parser) {
    parser->count = 0;
    parser->capacity = 10;
    parser->args = (Argument *)malloc(sizeof(Argument) * parser->capacity);
}

void add_argument(ArgumentParser *parser, const char *short_name, const char *long_name, int is_flag) {
    if (parser->count >= parser->capacity) {
        parser->capacity *= 2;
        parser->args = (Argument *)realloc(parser->args, sizeof(Argument) * parser->capacity);
    }
    parser->args[parser->count].short_name = short_name ? strdup(short_name) : NULL;
    parser->args[parser->count].long_name = long_name ? strdup(long_name) : NULL;
    parser->args[parser->count].value = NULL;
    parser->args[parser->count].is_flag = is_flag;
    parser->count++;
}

void parse_arguments(ArgumentParser *parser, int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < parser->count; j++) {
            if ((parser->args[j].short_name && strcmp(argv[i], parser->args[j].short_name) == 0) ||
                (parser->args[j].long_name && strcmp(argv[i], parser->args[j].long_name) == 0)) {
                if (parser->args[j].is_flag) {
                    parser->args[j].value = strdup("true");
                } else if (i + 1 < argc) {
                    parser->args[j].value = strdup(argv[++i]);
                }
                break;
            }
        }
    }
}

char* get_argument(ArgumentParser *parser, const char *name) {
    for (int i = 0; i < parser->count; i++) {
        if ((parser->args[i].short_name && strcmp(parser->args[i].short_name, name) == 0) ||
            (parser->args[i].long_name && strcmp(parser->args[i].long_name, name) == 0)) {
            return parser->args[i].value;
        }
    }
    return NULL;
}

int get_flag(ArgumentParser *parser, const char *name) {
    char *value = get_argument(parser, name);
    return value != NULL && strcmp(value, "true") == 0;
}

void free_parser(ArgumentParser *parser) {
    for (int i = 0; i < parser->count; i++) {
        if (parser->args[i].short_name) free(parser->args[i].short_name);
        if (parser->args[i].long_name) free(parser->args[i].long_name);
        if (parser->args[i].value) free(parser->args[i].value);
    }
    free(parser->args);
}
