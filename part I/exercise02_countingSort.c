#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"

int main()
{
    table_data values[1405];
    char *contents = (char *)malloc(sizeof(char) * LINE_SIZE);
    clock_t c1, c2;
    open_file("ocean.csv", values, contents);
    int k = sizeof(values) / sizeof(values[0]);
    c1 = clock();
    countingsort(values, k);
    c2 = clock();
    printArray(values, k);
    printf("====================\n");
    printf("Countingsort          %f sec\n", (float)(c2 - c1) / CLOCKS_PER_SEC);
    free(contents);
    exit(0);
}
