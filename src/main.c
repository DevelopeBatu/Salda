#include <stdio.h>
#include <stdlib.h>
#include "arg.h"
#include "lexer.h"
#include "list.h"

int main(int argc, char **argv) {
    char *input_file = NULL;
    int help = 0;

    process_arguments(argc, argv, &input_file, &help);

    if (!input_file) {
        printf("No input file specified.\n");
        usage(argv[0]);
        return 0;
    }

    printf("Input file: %s\n", input_file);

    List token_list;
    init_list(&token_list);

    tokenize_file(input_file, &token_list);

    print_list(&token_list);

    free_list(&token_list);

    return 0;
}
