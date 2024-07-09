#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"
#include "SaldaString.h"
#include "arg.h"

void usage(str program) {
    printf("Usage: %s [OPTIONS] [SUBCOMMANDS] <ARGS>\n", program);
    printf("Options:\n");
    printf("  -i, --input FILE    Specify input file\n");
    printf("  -h, --help          Show this help message\n");
}

void show_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
}

void process_arguments(int argc, char **argv, char **input_file, int *help) {
    ArgumentParser parser;
    init_parser(&parser);

    add_argument(&parser, "-i", "--input", 0);
    add_argument(&parser, "-h", "--help", 1);

    parse_arguments(&parser, argc, argv);

    *input_file = get_argument(&parser, "-i");
    *help = get_flag(&parser, "-h");

    if (*help) {
        usage(argv[0]);
        free_parser(&parser);
        exit(0);
    }

    if (!*input_file && argc == 2 && ends_with(argv[1], ".sl")) {
        *input_file = argv[1];
    }

    free_parser(&parser);
}
