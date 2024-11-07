#include <stdio.h>
#include <stdlib.h>

#define MIN_BASE 2
#define MAX_BASE 36

//displays help and exits program
void help()
{
    printf("\nBase Conversion Utility\n");
    printf("------------------------------------------\n");
    printf("This program converts numbers from decimal format to a specified base.\n\n");
    
    printf("Usage:");
    printf(" convert [OPTIONS]\n\n");

    printf("Options:\n");
    printf("  -b BASE           Specify a base between %d and %d for conversion\n" , MIN_BASE, MAX_BASE);
    printf("                    Default is base 16 (hexadecimal)\n");
    printf("\n  -r START FINISH   Convert a range of numbers from START to FINISH\n");

    printf("\nInteractive Mode:\n");
    printf("  If no range is specified with -r, you can enter numbers one by one for conversion.\n");
    printf("  Press CTRL+D to exit interactive mode.\n\n");

    exit(1);

}

//displays the correct usage for the program
void usage()
{
    fprintf(stderr, "Usage: convert [-b base] [-r START FINISH]");
    fprintf(stderr,"\n 1 < BASE < 37");
    fprintf(stderr, "\n START and FINISH are long integers\n");
    exit(1);
}