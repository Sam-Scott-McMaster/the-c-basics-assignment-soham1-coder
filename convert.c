
#include <stdio.h>
#include <stdlib.h>

void getInput(int argc, char *argv[], int *base);
int convert(long,int);


void getInput(int argc, char *argv[], int *base)
{

    *base = 16; //default base is hex

    for(int i = 1; i < argc; i++)
    {

        if (argv[i][0] == '-' && argv[i][1] == 'b') 
        {

            if (i + 1 < argc) //checks if there is a next argument
            {
                *base = atoi(argv[i + 1]); //converts next argument from string to int
            }
        }
    }

    if (*base < 2 || *base > 36) 
    {
        fprintf(stderr, "Invalid base. Please enter a number between 2 and 36.\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    long input = 0; 
    int base;

    getInput(argc, argv, &base);

    while (scanf("%ld", &input) != EOF) 
    {
        printf("Enter number to convert");
        convert(input,base);
        printf("\n");

}
    return 0;
}

int convert(long num, int base)
{
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //case for negative number
    if (num<0)
    {
        num = -num;
        printf('-');
    }

    //recursively converts given number to given base
    if (num>=base)
    {
        convert(num/base, base);
    }

    int digit = digits[num % base];

    printf("%d", digit); //prints each digit of new number


}
