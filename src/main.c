#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"
#include "SaldaString.h"

typedef char* str;

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

int main(int argc, char **argv) {
    ArgumentParser parser;
    init_parser(&parser);

    add_argument(&parser, "-i", "--input", 0);
    add_argument(&parser, "-h", "--help", 1);

    parse_arguments(&parser, argc, argv);

    char *input_file = get_argument(&parser, "-i");
    int help = get_flag(&parser, "-h");

    if (help) {
        usage(argv[0]);
        free_parser(&parser);
        return 0;
    }

    if (input_file) {
        printf("Input file: %s\n", input_file);
        //show_file_contents(input_file);
    } else if (argc == 2 && ends_with(argv[1], ".sl")) {
        printf("Single argument ends with .sl: %s\n", argv[1]);
        show_file_contents(argv[1]);
    } else {
        printf("No input file specified.\n");
        usage(argv[0]);
        return 0;
    }

    free_parser(&parser);
    return 0;
}
