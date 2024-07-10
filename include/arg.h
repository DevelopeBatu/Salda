#ifndef ARG_H
#define ARG_H

void usage(const char *program);
void process_arguments(int argc, char **argv, char **input_file, char **output_file, int *help);

#endif // ARG_H
