#ifndef ARG_H
#define ARG_H

typedef char* str;

void usage(str program);
void show_file_contents(const char *filename);
void process_arguments(int argc, char **argv, char **input_file, int *help);

#endif // ARG_H
