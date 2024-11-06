
#include <stdio.h>
#include <stdlib.h>

//function prototypes
void getInput(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode);
void convert(long,int);

void usage()
{
    fprintf(stderr, "Usage: convert [-b base] [-r START FINISH]");
    fprintf(stderr,"\n 1 < BASE < 37");
    fprintf(stderr, "\n START and FINISH are long integers\n");
    exit(1);
}


void getInput(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode)
{

    *base = 16; //default base is hex
    *start = 0;
    *finish = 0;
    *range_mode = 0;

    //iterates through given input
    for(int i = 1; i < argc; i++)
    {

        //checks if base should be changed
        if (argv[i][0] == '-' && argv[i][1] == 'b') 
        {

            if (i + 1 < argc) //checks if there is a next argument
            {
                *base = atoi(argv[i + 1]); //converts next argument from string to int and sets base to that value 
            }
        }

        //checks if conversion should use a range
        else if (argv[i][0] == '-' && argv[i][1] == 'r')
        {
            if (i + 2 < argc)
            {
                *start = atol(argv[i+1]);
                *finish = atol(argv[i+2]);
                *range_mode = 1;
            }
        }
    }

    //invalid base
    if (*base < 2 || *base > 36) 
    {
        usage();
    }
}

int main(int argc, char *argv[])
{
    long input = 0; 
    int base;
    long start;
    long finish;
    int range_mode;

    getInput(argc, argv, &base, &start, &finish, &range_mode);

    if (range_mode)
    {
        //convert a range of numbers
        for (long i = start; i <= finish; i++) 
        {
            convert(i, base);
            printf("\n");
        }
    }        

    else
    {
        //convert numbers one at a time
        printf("Enter numbers to convert\n");
        while (scanf("%ld", &input) != EOF) 
        {
            printf("Converted Number: ");
            convert(input, base);
            printf("\n");
        }
    }

    return 0;
}

void convert(long num, int base)
{
    //An array of all characters in all bases
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //case for negative number
    if (num<0)
    {
        num = -num;
        putchar('-');
    }

    //recursively converts given number to given base
    if (num>=base)
    {
        convert(num/base, base);
    }

    char digit = digits[num % base];

    putchar(digit); //prints each digit of new number

}
