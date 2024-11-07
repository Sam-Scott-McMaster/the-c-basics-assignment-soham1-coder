
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convertNum.h"
#include "convertUsageHelp.h"

#define MIN_BASE 2
#define MAX_BASE 36

//function prototypes
void getInput(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode);

//obtains input user and ensures the input is valid
void getInput(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode)
{

    *base = 16; //default base is hex
    *start = 0;
    *finish = 0;
    *range_mode = 0;

    //iterates through given input
    for(int i = 1; i < argc; i++)
    {

        //checks if user wants help
        if (strcmp(argv[i], "--help")== 0)
        {
            help();
        }

        //checks if base should be changed
        else if (argv[i][0] == '-' && argv[i][1] == 'b') 
        {

            if (i + 1 < argc) //checks if there is a next argument
            {
                *base = atoi(argv[i + 1]); //converts next argument from string to int and sets base to that value 
            }

            else
            {
                usage(); //if There is no next argument after "-b" then calls usage
            }

            i++; 
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


            else
            {
                usage(); //if There are no two arguments after "-r" then calls usage
            }

            i+=2;
        }

        else
        {
            usage(); //calls usage if there are any unrecognized arguments
        }
    }

    //invalid base
    if (*base < MIN_BASE || *base > MAX_BASE) 
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
            convertNum(i, base);
            printf("\n");
        }
    }        

    else
    {
        //convert numbers one at a time
        //printf("Enter numbers to convert\n");
        while (scanf("%ld", &input) != EOF) 
        {
            //printf("Converted Number: ");
            convertNum(input, base);
            printf("\n");
        }
    }

    return 0;
}
