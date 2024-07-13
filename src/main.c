#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"
#include "lexer.h"
#include "list.h"
#include "parser.h"
#include "arg.h"

// Declare the c_file as an external variable
extern char* c_file;

void write_to_output_file(const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("Could not open output file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", c_file);
    fclose(file);
    free(c_file);
}

int main(int argc, char **argv) {
    char *input_file = NULL;
    char *output_file = NULL;
    int help = 0;

    process_arguments(argc, argv, &input_file, &output_file, &help);

    if (!input_file) {
        printf("No input file specified.\n");
        usage(argv[0]);
        return 0;
    }

    if (!output_file) {
        output_file = (char *)malloc(strlen(input_file) + 3);  // .c + null terminator
        strcpy(output_file, input_file);
        strcat(output_file, ".c");
    }

    printf("Input file: %s\n", input_file);
    printf("Output file: %s\n", output_file);

    List token_list;
    init_list(&token_list);

    tokenize_file(input_file, &token_list);

    parse(token_list);

    write_to_output_file(output_file);

    free(output_file);
    free_list(&token_list);

    return 0;
}
