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