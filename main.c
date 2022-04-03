#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundamentals.h"

int main()
{
    int x = 5;
    int y = 10;

    swap(&x, &y, INT);
    printf("\n%d %d\n", x, y);

    return 0;
}