#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//converts given number to given base
void convertNum(long num, int base)
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
        convertNum(num/base, base);
    }

    char digit = digits[num % base];
    putchar(digit); //prints each digit of new number
}