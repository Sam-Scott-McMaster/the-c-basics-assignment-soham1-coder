#include <stdio.h>
#include <stdlib.h>

void getInput();
int convert(long,int);


void getInput()
{

int num = 0; //
int base = 16; //initializes base as hex

int *pNum = &num;
int *pBase = &base;

printf("Enter a number to convert");
scanf("%d",&num);

printf("Enter a base");
scanf("%d", &base);

}

void main()
{
    getInput();

}

int convert(long num, int base)
{

int remainder = 0;



}