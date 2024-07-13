#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"
#include "SaldaString.h"
#include "arg.h"

void usage(const char *program) {
    printf("Usage: %s [OPTIONS] [SUBCOMMANDS] <ARGS>\n", program);
    printf("Options:\n");
    printf("  -i, --input FILE    Specify input file\n");
    printf("  -o, --output FILE   Specify output file\n");
    printf("  -h, --help          Show this help message\n");
}

void process_arguments(int argc, char **argv, char **input_file, char **output_file, int *help) {
    ArgumentParser parser;
    init_parser(&parser);

    add_argument(&parser, "-i", "--input", 0);
    add_argument(&parser, "-o", "--output", 0);
    add_argument(&parser, "-h", "--help", 1);

    parse_arguments(&parser, argc, argv);

    *input_file = get_argument(&parser, "-i");
    *output_file = get_argument(&parser, "-o");
    *help = get_flag(&parser, "-h");

    if (*help) {
        usage(argv[0]);
        free_parser(&parser);
        exit(0);
    }

    if (!*input_file && argc >= 2 && ends_with(argv[1], ".sl")) {
        *input_file = argv[1];
    }

    free_parser(&parser);
}
