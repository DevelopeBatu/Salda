#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arg.h"
#include "lexer.h"
#include "list.h"
#include "parser.h"

extern char* c_file; // parser.c dosyasında tanımlandığını belirtmek için extern kullanın

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

    printf("Input file: %s\n", input_file);

    List token_list;
    init_list(&token_list);

    tokenize_file(input_file, &token_list);

    parse(token_list);

    if (!output_file) {
        size_t input_len = strlen(input_file);
        output_file = (char *)malloc(input_len + 3); // +3 for ".c" and null terminator
        strcpy(output_file, input_file);
        strcat(output_file, ".c");
    }

    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("Could not open output file");
        return 1;
    }
    fprintf(file, "%s", c_file);
    fclose(file);

    printf("Output written to %s\n", output_file);

    free(output_file);
    free(c_file); // Belleği serbest bırakın

    free_list(&token_list);

    return 0;
}
