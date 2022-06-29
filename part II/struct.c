#include <stdio.h>
#include <time.h>
#include "struct.h"

void print_equal(int number)
{
    int i;

    for (i = 0; i < number; i++)
        printf("=");
    printf("\n");
}

int check_allocation(void *p)
{
    if (!p)
    {
        fprintf(stderr, "Error allocating memory!");
        return FALSE;
    }

    return TRUE;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}