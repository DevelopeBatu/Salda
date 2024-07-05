#ifndef ARGPARSE_H
#define ARGPARSE_H

typedef struct {
    char *short_name;
    char *long_name;
    char *value;
    int is_flag;
} Argument;

typedef struct {
    Argument *args;
    int count;
    int capacity;
} ArgumentParser;

void init_parser(ArgumentParser *parser);
void add_argument(ArgumentParser *parser, const char *short_name, const char *long_name, int is_flag);
void parse_arguments(ArgumentParser *parser, int argc, char **argv);
char* get_argument(ArgumentParser *parser, const char *name);
int get_flag(ArgumentParser *parser, const char *name);
void free_parser(ArgumentParser *parser);

#endif // ARGPARSE_H
